#include <string>
#include "Student.h"
#include <iostream>

Student::Student(float _gpa, std::string name): Person(name)  {
   gpa = _gpa;
}

float Student::getGPA( ) {
   return gpa;
}

void Student::print() {
   std::cout<<getName()<<" and "<<gpa<<std::endl;
}