#include <iostream>
#include <list>
#include "Simulation.h"
#include <unistd.h>

using namespace std;

/////////////////
// Constructor
/////////////////

Simulation::Simulation(int windowCount, list<Student> simList)
{
  for (list<Student>::iterator s=simList.begin(); s != simList.end(); ++s)
  {
    allStudents.push_front((*s));
  }
  //allStudents = simList;
  for(int i=0 ; i<windowCount ; ++i)
  {
    Window tempWindow;
    windows.push_front(tempWindow);
  }


  cout << "Creating a simulation with " << allStudents.size() << " Students and " << windows.size() << " Windows" << endl;
  for (list<Student>::iterator s=allStudents.begin(); s != allStudents.end(); ++s)
  {
    cout << "    A student with activation time " << (*s).timeActivation << " and requiring time " << (*s).timeRequired << endl;
  }
  cout << endl;
  currentTime = 0;
}



//////////////////////
// Timing Function
//////////////////////

// iterates simulation by 1 time unit
void Simulation::tick()
{
  sleep(2);
  // first, make moves:
  //    (out of line) -> (line)
  //    (line) -> (windows)
  insertStudents();
  fillWindows();


  // then, iterate time for all students in line
  for(list<Student>::iterator s=allStudents.begin(); s != allStudents.end(); ++s)
  {
    (*s).tick();
  }

  cout << "Checking all windows...";
  for(list<Window>::iterator w=windows.begin(); w != windows.end(); ++w)
  {
    (*w).checkStudent();
  }
  cout << "Done!" << endl << endl;

  ++currentTime;
}



/////////////////////////
// Migration Functions
/////////////////////////

// check allStudents for any students ready to join the line
void Simulation::insertStudents()
{
  cout << "Attempting to move students to line... [Current Time:" << currentTime << "]" << endl;
  for(list<Student>::iterator s=allStudents.begin(); s != allStudents.end(); ++s){
    cout << "    Comparing student(act. " << (*s).timeActivation << ", req. " << (*s).timeRequired << ")... ";
    if ((*s).timeActivation == currentTime && !(*s).activated){
      Student *studentPtr = &(*s);
      studentPtr->activated = true;
      studentLine.enqueue(studentPtr);
      cout << "Student added!" << endl;
    }
    else
      cout << "Not Added" << endl;
  }
}

// check for empty windows and insert the next students from the line into them
// then, check if a student is done at a window to remove them and record their stats
void Simulation::fillWindows()
{
  cout << "Filling window with students... " << endl;
  for(list<Window>::iterator w=windows.begin(); w != windows.end(); ++w){
    if (studentLine.empty())
    {
      cout << "line is empty" << endl;
      continue;
    }
    if ((*w).student == NULL){
      cout << "(Student) -> (Window)" << endl;
      (*w).enterStudent(studentLine.dequeue());
    }
    else
      cout << "No windows avaliable" << endl;
  }
}



//////////////////////////
// Statistics Functions
//////////////////////////

// determines if all students have been helped
bool Simulation::simulationDone()
{
  int unfinished = 0;
  bool finished = true;
  for(list<Student>::iterator s=allStudents.begin(); s != allStudents.end(); ++s){
    if ((*s).timeRequired != 0)
    {
      finished = false;
      ++unfinished;
    }
  }
  cout << unfinished << " students are not done yet" << endl;
  return finished;
}


// collect all statistics of the simulation and print information to console
void Simulation::printStatistics()
{
// collect data from simulation
  list<int> studentIdleTimes;
  for(list<Student>::iterator s=allStudents.begin(); s != allStudents.end(); ++s)
    studentIdleTimes.push_front((*s).timeIdle);

  list<int> windowIdleTimes;
  for(list<Window>::iterator w=windows.begin(); w != windows.end(); ++w)
    windowIdleTimes.push_front((*w).timeIdle);

// calculate values

  //students
  double sMean = 0;
  int sIdleOverTen = 0;
  int sLongestWait = 0;
  for(list<int>::iterator i=studentIdleTimes.begin(); i != studentIdleTimes.end(); ++i)
  {
    sMean += *i;
    if (*i > 10)
      ++sIdleOverTen;
    if (*i > sLongestWait)
      sLongestWait = *i;
  }
  sMean = (sMean / (double)studentIdleTimes.size());

  double median = 0;
  studentIdleTimes.sort();
  while (studentIdleTimes.size() > 2){
    studentIdleTimes.pop_back();
    studentIdleTimes.pop_front();
  }
  for(list<int>::iterator i=studentIdleTimes.begin(); i != studentIdleTimes.end(); ++i){
    median+=*i;
  }
  median = (median / (double)studentIdleTimes.size());

  //windows
  double wMean = 0;
  int wIdleOverFive = 0;
  int wLongestWait = 0;
  for(list<int>::iterator i=windowIdleTimes.begin(); i != windowIdleTimes.end(); ++i)
  {
    wMean += *i;
    if (*i > 10)
      ++wIdleOverFive;
    if (*i > wLongestWait)
      wLongestWait = *i;
  }
  wMean = (wMean / (double)windowIdleTimes.size());

  cout << "          Simulation Statistics" << endl
       << "-----------------------------------------" << endl
       << "Mean Student Wait Time: " << sMean << " minutes" << endl
       << "Median Student Wait Time: " << median << " minutes" << endl
       << "Longest Student Wait Time: " << sLongestWait << " minutes" << endl
       << "Number of Students who waited over 10 minutes: " << sIdleOverTen << endl
       << "Mean Window Idle Time: " << wMean << " minutes" << endl
       << "Longest Window Idle Time: " << wLongestWait << endl
       << "Number of Windows that waited over 5 minutes: " << wIdleOverFive << endl;
}
