#include <iostream>
#include "BigObject.h"

void foo(const BigObject& bObj, int i) {
  int j = bObj.array[i]; // allowed, only reading
  // bObj.array[i] = -i; // not allowed; modifying const ref; 
                         // will give compilation error
  std::cout << j << std::endl;
}

int main(int argc, char* argv[ ]) { 
   BigObject b;

   std::cout << "before foo b 3: " << b.array[3] << std::endl;
   foo(b, 3);
   std::cout << "after foo b 3: " << b.array[3] << std::endl;
}   
