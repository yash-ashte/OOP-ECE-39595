#include <iostream>
#include <string>
#include "Obj.h"

int main(int argc, char* argv[ ]) { 
   Obj obj1 = Obj(1);
   Obj& obj1R= obj1;
   Obj obj2(2);
   Obj& obj2R = obj2;
   std::cout << "obj1R: " << obj1R.i << ", obj2R: " << obj2R.i << std::endl;
   obj1R = obj2R;
   std::cout << "obj1R: " << obj1R.i << ", obj2R: " << obj2R.i << std::endl;
   obj1R.i = 500;
   std::cout << "obj1R: " << obj1R.i << ", obj2R: " << obj2R.i << std::endl;
}   