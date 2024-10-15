#include <string>
#include "TeachingAssistant.h"
#include <iostream>

TeachingAssistant::TeachingAssistant(float gpa, std::string name, std::string _course): Student(gpa, name)  {
   course = _course;
}

std::string TeachingAssistant::getCourse( ) {
   return course;
}