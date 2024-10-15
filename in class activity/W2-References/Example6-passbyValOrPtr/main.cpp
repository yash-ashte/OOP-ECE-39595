#include <iostream>

void foo(int i, int* ip) {
   int j = i;
   i = 4;
   *ip = 5;
   ip = nullptr;
}

int main(int argc, char* argv[ ]) { 
   int k = 10;
   int m = 11;
   int* pm = &m;
   foo(k, pm);
   std::cout << "k: " << k << std::endl;
   if (pm != nullptr) {
      std::cout << "m: " << *pm << std::endl;
   } else {
      std::cout << "pm == nullptr" << std::endl;
   }
}