#include "Simulation.h"

/////////////////
// Constructor
/////////////////

Simluation::Simulation(int wind, List<Student> studentList)
{
  studentsArriving = studentList;

  windows = new List<Window>();
  for(int i=0 ; i<wind ; ++i)
    windows.insert(new Window());

  studentLine = new LinkedQueue<Student>();

  int currentTime=0;

  waitTimes = new List<int>();
}



//////////////////////
// Timing Functions
//////////////////////

// iterates simulation by 1 time unit
void Simluation::tick()
{
  // first, make moves:
  //    (out of line) -> (line)
  //    (line) -> (windows)
  insertStudents();
  fillWindows();

  // then, run windows and line functions
  runWindows();
  runLine();

  ++currentTime;
}

// iterates windows by 1 time unit
void Simluation::runWindows()
{
  for(Window w : windows){
    w.serviceStudent();
    if (w.student->timeRequired == 0){
      waitTimes.insert(w.removeStudent().timeIdle);
    }
  }
}

// increases idle time of all students in line
void Simluation::runLine()
{
  LinkedQueue<Student> tempQ;
  Student tempS;
  while (!studentLine.empty()){
    tempS = studentLine.dequeue();
    tempS.timeIdle = (tempS.timeIdle+1);
    tempQ.enqueue(tempS);
  }

  while(!tempQ.empty()){
    studentLine.enqueue(tempQ.dequeue());
  }
}



/////////////////////////
// Migration Functions
/////////////////////////

// check studentsArriving for any students ready to join the line
void Simluation::insertStudents()
{
  for(Student s : studentsArriving){
    if (s.timeActivation == currentTime){
      studentLine.enqueue(s);
      studentsArriving.remove(s);
    }
  }
}

// check for empty windows and insert the next students from the line into them
void Simluation::fillWindows()
{
  for(Window w : windows){
    if (w.student == NULL)
      w.student = studentLine.dequeue();
  }
}
