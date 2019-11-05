#include "Window.h"

//////////////////
// Constructors
//////////////////

// base constructor
Window::Window()
{
  student = NULL;

  timeIdle = 0;
}

// destructor, to clear out any remaining pointers
Window::~Window()
{
  student = NULL;
}

////////////////////
// Class Behavior
////////////////////

Window::void serviceStudent()
{
  if (student->timeRequired == 0)
    return;
  if (student == NULL)
    ++timeIdle;
  else
    student->tick();
}
