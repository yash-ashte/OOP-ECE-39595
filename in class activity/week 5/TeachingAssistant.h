#ifndef TEACHINGASSISTANT_H_
#define TEACHINGASSITSANT_H_

#include <string>
#include "Student.h"

class TeachingAssistant : public Student {

private:
    std::string course;

public:
   TeachingAssistant(float gpa, std::string name, std::string _course);
   std::string getCourse( );
   //void print();
};

#endif /* TEACHINGASSISTANT_H_ */