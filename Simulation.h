/*
// Ayden Best - 2317839
// Student Class
//      Handles logic and lists for entire simulation
*/

#include <iostream>
#include <list>
#include "./LinkedQueue/LinkedQueue.h"
#include "Window.h"

using namespace std;

class Simulation{
private:

  // base lists
  list<Student> allStudents;       // Students in the simulation
  list<Window> windows;                 // Windows
  LinkedQueue<Student*> studentLine;     // The line of pointers to students

  // timing integer
  int currentTime;



public:

  //
  // Initialization
  //

  Simulation(int windows, list<Student> studentList); // constructor



  //
  // timing function
  //

  void tick();
  // iterates simulation by 1 time unit



  //
  // migration functions
  //

  void insertStudents();
  // check allStudents for any students ready to join the line

  void fillWindows();
  // check for empty windows and insert the next students from the line into them



  //
  // statistics functions
  //

  bool simulationDone();
  // determines if all students have been helped

  void printStatistics();
  // collect all statistics of the simulation and print information to console

};
