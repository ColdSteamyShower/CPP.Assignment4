#include "Student.h"

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

  if (atWindow)
    --timeRequired;
  else
    ++timeIdle;
}

void Student::activate()
{
  activated = true;
}
