#include <string>
#include "Person.h"
#include <iostream>

Person::Person(std::string _name) {
   name = _name;
}

std::string Person::getName( ) {
   return name;
}

void Person::print() {
   std::cout<<name<<std::endl;
}