/*
// Ayden Best - 2317839
// Student Class
//      Handles statistics for each student.
*/


class Student{
private:

  friend class Simulation; // share class with Simulation
  friend class Window;     // share class with Window

  int timeRequired;   // how long they need at a window
  int timeActivation; // the time at which they are activated
  int timeIdle;       // amount of time the student has been waiting
  bool activated;     // whether the student has been activated
  bool atWindow;      // whether the student is at a window

  // constructors
  Student();
  Student(int time, int act); // takes ints to set timeRequired and timeActivation accordingly

  // functions
  void tick();     // ticks time for student
  void activate(); // activates the student(puts them in line)

};
