#ifndef STUDENT_H
#define STUDENT_H
#include "utils_student.h"
using namespace std;

bool isValidDOB(const string&);
bool isValidPhone(const string&);
bool isValidFullName(const string&);

class Student {
private:
    string fullName, doB, sex, phoneNumber, universityName, gradeLevel;

public:
    Student(string, string, string, string, string, string);
    
    string getFullName();

    string getPhoneNumber();

    virtual float getGPA();

    virtual int getEnglishScore();

    virtual float getEntryTestScore();

    virtual void ShowMyInfor();

    virtual string getType() = 0;

    virtual ~Student();
};

#endif