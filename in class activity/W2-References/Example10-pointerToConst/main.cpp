#include <iostream>
#include "BigObject.h"

void foo(const BigObject* bObj, int i) {
  bObj->array[i] = -i; // not allowed, will give compilation error
}

int main(int argc, char* argv[ ]) { 
  //BigObject* b = new BigObject( );
  BigObject b;

   std::cout << "before foo b 3: " << b.array[3] << std::endl;
   foo(&b, 3);
   std::cout << "after foo b 3: " << b.array[3] << std::endl;
}   
