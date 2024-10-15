#include <iostream>
#include "Obj.h"

int main(int argc, char* argv[ ]) { 
   Obj* obj1 = new Obj(1);
   Obj* obj2 = new Obj(2);
   std::cout << "obj1: " << obj1->i << ", obj2: " << obj2->i << std::endl;
   obj1 = obj2;
   std::cout << "obj1: " << obj1->i << ", obj2: " << obj2->i << std::endl;
   obj1->i = 500;
   std::cout << "obj1: " << obj1->i << ", obj2: " << obj2->i << std::endl;

}   