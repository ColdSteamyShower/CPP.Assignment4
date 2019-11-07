#include <iostream>
#include <list>
#include "Simulation.h"

using namespace std;

int main(){
  list <int> ints;
  ints.push_front(1);
  ints.push_front(2);
  ints.push_front(3);

  for (list<int>::iterator i=ints.begin(); i != ints.end(); ++i){
    cout << *i << endl;
  }

  list<Student> students;
  Student student1(10, 2);
  Student student2(5, 3);
  Student student3(5, 5);
  students.push_front(student1);
  students.push_front(student2);
  students.push_front(student3);

  Simulation testSim(1, students);

  while (!testSim.simulationDone()){
    testSim.tick();
  }
  testSim.printStatistics();

}
