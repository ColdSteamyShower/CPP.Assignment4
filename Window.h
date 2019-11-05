/*
// Ayden Best - 2317839
// Student Class
//      Handles window logic
*/

#include "Student.h"

class Window{
private:
  friend class Simulation;

  //functionality objects
  bool occupied;
  Student *student; // pointer to student who is at the window

  //statistics objects
  int timeIdle;

public:

  Window();

  void serviceStudent(); // decreases the student's required time. if that time is 0, remove the student and add stats

  Student removeStudent(); // empties window and returns the student inside

};
