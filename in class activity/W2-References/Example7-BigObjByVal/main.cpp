#include <iostream>
#include "BigObject.h"

void foo(BigObject bObj, int i) {
   bObj.array[i] = -i;
}

int main(int argc, char* argv[ ]) { 
   BigObject b;
   std::cout << "before foo(b,3): " << b.array[3] << std::endl;
   foo(b, 3);
   std::cout << "after foo(b,3): " << b.array[3] << std::endl;
}   
