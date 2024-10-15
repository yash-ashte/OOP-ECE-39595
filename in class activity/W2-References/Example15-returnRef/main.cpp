#include <iostream>
#include <string>
#include "Obj.h"


void inc(Obj &objRef){
  objRef.i++;
}

Obj& incWithRefReturn(Obj &objRef){
  objRef.i++;
  return(objRef);
}

Obj& incWithRefReturnAlt(Obj &objRef){
  Obj obj1(2);
  objRef.i++;
  obj1 = objRef;
  return(obj1);
}

const Obj& incWithConstRefReturn(Obj &objRef){
  objRef.i++;
  return(objRef);
}


int main(int argc, char* argv[ ]) { 
   Obj obj = Obj(1);
   std::cout << "obj.i " << obj.i << std::endl;
   inc(obj);
   std::cout << "obj.i " << obj.i << std::endl;
   // inc(inc(obj)); // won't compile. Not allowed.

   incWithRefReturn(obj);
   std::cout << "obj.i " << obj.i << std::endl;

   incWithRefReturn(incWithRefReturn(obj));
   std::cout << "obj.i " << obj.i << std::endl;


   incWithConstRefReturn(obj);
   std::cout << "obj.i " << obj.i << std::endl;

   // incWithConstRefReturn(incWithConstRefReturn(obj)); // won't compile. disallowed.

   Obj &objRef=incWithRefReturnAlt(obj);
   std::cout << "obj.i " << obj.i << std::endl;
   std::cout << "objRef.i " << objRef.i << std::endl;


}   