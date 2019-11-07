/*
// Ayden Best - 2317839
// Student Class
//      Handles window logic
*/

#include <iostream>
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
  ~Window();

  void enterStudent(Student *sPtr);
  // puts a student into the window unless it is already occupied

  void checkStudent();
  // checks on the student inside. if that time is 0, remove the student and add stats. if there is no student, increase idle time

  void removeStudent();
  // empties the window and resets the student's activated and atWindow booleans

};
