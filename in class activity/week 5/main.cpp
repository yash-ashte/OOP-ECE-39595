#include "TeachingAssistant.h"
#include <iostream>

int main(int argc, char* argv[ ]) {
   Person p = Person("Yash");
   Student s = Student(2.9, "Sam");
   std::cout << "Name = " << s.getName() << " GPA = " << s.getGPA() << std::endl;
   //p.print();
   //s.print();


   Person *personPtr = &s; 
   Student *studentPtr = &s;

   personPtr->print();
    studentPtr->print();

    TeachingAssistant ta1 = TeachingAssistant(3.8, "Julie", "OO Programming");
}

/*
Answer for Part 1 Step 1:
Output = 
Yash
Sam

Answer for Part 1 Step 2:
Output=
Yash
Sam and 2.9

Answer for Part 1 Step 3:
Commenting out that print function would not print the parent but have no impact on the child class

Answer for Part 2:
We get an error saying "invalid conversion from ‘Person*’ to ‘Student*’"
Commenting L1 still gives this error but commenting L2 fixes the problem.

Answer for Part 3 Step 1:
Output=
Sam
Sam and 2.9

Answer for Part 3 Step 2:
Output=
Sam and 2.9
Sam and 2.9



*/
