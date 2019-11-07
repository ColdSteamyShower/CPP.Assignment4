#include <iostream>
#include "Student.h"

using namespace std;

//////////////////
// Constructors
//////////////////

// default constructor
Student::Student()
{
  timeRequired = 0;
  timeActivation = 0;
  timeIdle = 0;
  activated = false;
  atWindow = false;
}

// real constructor
Student::Student(int activate, int required)
{
  timeRequired = required;
  timeActivation = activate;
  timeIdle = 0;
  activated = false;
  atWindow = false;
}

////////////////////
// Class Behavior
////////////////////

void Student::tick()
{
  if (!activated)
  {
    return;
  }
  else if (atWindow)
  {
    --timeRequired;
  }
  else
  {
    ++timeIdle;
  }
}

void Student::print()
{
  cout << "------------------------------\n"
       << "Activated at " << timeActivation << endl
       << "Time Required: " << timeRequired << endl
       << "Time Spent Idle: " << timeIdle << endl << endl;
}
