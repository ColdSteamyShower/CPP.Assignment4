/*
// Ayden Best - 2317839
// Student Class
//      Handles logic and lists for entire simulation
*/

#include "./LinkedQueue/DoublyLinkedList.h"
#include "./LinkedQueue/LinkedQueue.h"
#include "Student.h"
#include "Window.h"

class Simulation{
private:

  DoublyLinkedList<Student> studentsArriving;   // Students not yet in the line
  DoublyLinkedList<Window> windows;             // Windows
  LinkedQueue<Student> studentLine;             // The line of students

  int currentTime;


public:

  Simulation(int windows); // constructor




};
