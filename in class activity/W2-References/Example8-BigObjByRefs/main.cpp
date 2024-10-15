#include <iostream>
#include "BigObject.h"

void foo(BigObject& bObj, int i) {
   bObj.array[i] = -i;
}

int main(int argc, char* argv[ ]) { 
   BigObject b;

   //BigObject &bref; Does not compile. References must be initialized
   //  bref=b;

   std::cout << "b.array[1] = " << b.array[1] << std::endl;
   BigObject& bRef = b; // bind b to bRef
   bRef.array[1]=5; // changes to bRef will impact b
   std::cout << "b.array[1] = " << b.array[1] << std::endl;


   std::cout << "before foo b 3: " << b.array[3] << std::endl;
   foo(b, 3);
   std::cout << "after foo b 3: " << b.array[3] << std::endl;
}   
