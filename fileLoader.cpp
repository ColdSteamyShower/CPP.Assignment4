#include <iostream>
#include <list>
#include <fstream>
#include "fileLoader.h"

using namespace std;

// Reads a file to get the number of windows from it
int readWindows(string file)
{
  ifstream inFile(file);
  int windows;
  getline(inFile, windows);
  inFile.close();
  return windows;
}

// Reads a file to get the students from it
list<Student> readStudents(string file)
{
  list<Student> studentList;
  ifstream inFile(file);
  int temp;
  inFile >> temp; // skip first line for being the window count
  int activation;
  int students;
  while (getline(inFile, line))
  {
    while (students > 0){
      inFile >> temp;
      Student tempStudent(activation, temp);
      studentList.push_front(tempStudent);
    }
  }
  return studentList;
}
