#ifndef REGULAR_STUDENT_H
#define REGULAR_STUDENT_H
#include "student_university.h"

class RegularStudent : public Student{
public:
    RegularStudent(){}

    RegularStudent(string, string, string, int, float);

    bool isRegular() override;

    void displayStudent() override;
};

#endif