#include <iostream>
#include <list>
#include "Simulation.h"

using namespace std;

int main(){

  list<Student> students;
  Student student1(10, 2);
  Student student2(5, 3);
  Student student3(5, 5);
  students.push_front(student1);
  students.push_front(student2);
  students.push_front(student3);

  Simulation testSim(2, students);

  while (!testSim.simulationDone()){
    testSim.tick();
  }
  testSim.printStatistics();

}
