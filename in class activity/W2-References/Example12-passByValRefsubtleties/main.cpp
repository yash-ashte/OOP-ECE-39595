#include <iostream>
#include "Obj.h"

void foo1(Obj objVar) {
   std::cout << "foo1" << std::endl;
   objVar.i ++;
}

void foo2(Obj& objRef) {
  std::cout << "foo2" << std::endl;
      objRef.i ++;
}

int main(int argc, char* argv[ ]) { 
   Obj oVar(-1);
   Obj&  oRef = oVar;
   foo1(oVar); // S0
   std::cout << oVar.i << std::endl;
   foo1(oRef); // S1
   std::cout << oVar.i << std::endl;
   foo2(oVar); // S2
   std::cout << oVar.i << std::endl;
   foo2(oRef); // S3
   std::cout << oVar.i << std::endl;
}   
   