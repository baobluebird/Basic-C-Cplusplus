#ifndef SCHOOL_H
#define SCHOOL_H
#include "class.h"
#define AddStudent 1
#define DisplayStudent20Years 2
#define FindStudentSameAgeAndAddress 3
class School{
    private:
        vector<Class> listClass;
    public:
        void addClass();
        
        void displayStudent20Years();

        void findStudentSameAgeAndAddress(int, string);

        void displaySchool();
};

#endif