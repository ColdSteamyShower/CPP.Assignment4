#include <iostream>
#include "Student.h"

using namespace std;

//////////////////
// Constructors
//////////////////

// default constructor
Student::Student()
{
  int timeRequired = 0;
  int timeActivation = 0;
  int timeIdle = 0;
  bool activated = false;
  bool atWindow = false;
}

// real constructor
Student::Student(int activate, int required)
{
  int timeRequired = required;
  int timeActivation = activate;
  int timeIdle = 0;
  bool activated = false;
  bool atWindow = false;
}

////////////////////
// Class Behavior
////////////////////

void Student::tick()
{
  if (!activated)
    return;
  else if (atWindow)
    --timeRequired;
  else
    ++timeIdle;
}

void Student::print()
{
  cout << "------------------------------\n"
       << "Activated at " << timeActivation << endl
       << "Time Required: " << timeRequired << endl
       << "Time Spent Idle: " << timeIdle << endl << endl;
}
