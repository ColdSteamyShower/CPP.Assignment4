/*
// Ayden Best - 2317839
// Student Class
//      Handles logic and lists for entire simulation
*/

#include <list>
#include "./LinkedQueue/LinkedQueue.h"
#include "Student.h"
#include "Window.h"

class Simulation{
private:

  // base lists
  List<Student> studentsArriving;       // Students not yet in the line
  List<Window> windows;                 // Windows
  LinkedQueue<Student> studentLine;     // The line of students

  // timing integer
  int currentTime;

  // statistics
  List<int> waitTimes;

public:

  //
  // Initialization
  //

  Simulation(int windows, List<Student> studentList); // constructor



  //
  // timing functions
  //

  void tick();
  // iterates simulation by 1 time unit

  void runWindows();
  // iterates windows by 1 time unit

  void runLine();
  // increases idle time of all students in line



  //
  // migration functions
  //

  void insertStudents();
  // check studentsArriving for any students ready to join the line

  void fillWindows();
  // check for empty windows and insert the next students from the line into them


};
