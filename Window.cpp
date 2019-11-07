#include <iostream>
#include "Window.h"

using namespace std;

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

void Window::enterStudent(Student *sPtr)
{
  if (student != NULL){
  }
  student = sPtr;
  student->atWindow = true;
}

void Window::checkStudent()
{

  if (student == NULL)
  {
    ++timeIdle;
  }
  else if (student->timeRequired == 0)
  {
    removeStudent();
  }
}

void Window::removeStudent()
{
  student->atWindow = false;
  student->activated = false;
  student = NULL;
}
