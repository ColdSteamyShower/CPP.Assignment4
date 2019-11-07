#include <iostream>
#include <list>
#include "./Simulation/Simulation.h"
#include "fileLoader.h"

using namespace std;

int main(){

  list<Student> students;
  Student student1(5, 2);
  Student student2(3, 10);
  Student student3(1, 8);
  students.push_front(student1);
  students.push_front(student2);
  students.push_front(student3);

  Simulation testSim(4, students);

  while (!testSim.simulationDone()){
    testSim.tick();
  }
  testSim.printStatistics();

}
