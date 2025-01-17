// main.cpp
#include "mytime.h"
#include <iostream>

int main() {
    Time t1(2, 22);  // 2 days, 22 hours
    Time t2(1, 6);   // 1 day, 6 hours

    // Test addition
    Time t3 = t1 + t2;
    std::cout << "t1 + t2: " << t3 << "\n";

    // Test Time * int
    Time t4 = t1 * 3;
    std::cout << "t1 * 3: " << t4 << "\n";

    // Test int * Time
    Time t5 = 3 * t1;
    std::cout << "3 * t1: " << t5 << "\n";

    // Test Time * Time
    Time t6 = t1 * t2;
    std::cout << "t1 * t2: " << t6 << "\n";

    return 0;
}
