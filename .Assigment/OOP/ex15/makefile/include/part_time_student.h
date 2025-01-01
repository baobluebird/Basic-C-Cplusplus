#ifndef PART_TIME_STUDENT_H
#define PART_TIME_STUDENT_H
#include "student_university.h"

class PartTimeStudent : public Student{
private:
    string linkedLocation;

public:
    PartTimeStudent();

    PartTimeStudent(string, string, string, int, float, string);

    bool isRegular() override;

    void inputLinkedLocation();

    void inputStudent() override;

    void displayStudent() override;

    string getLinkedLocation() override;
};

#endif