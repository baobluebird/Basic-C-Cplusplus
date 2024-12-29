#ifndef CLASS_H
#define CLASS_H

#include "student.h"

class Class{
    private:
        string nameClass;
        vector<shared_ptr<Student>> listStudents;
    public:
        Class();
        
        void inputInfoClass();

        void displayInfoClass();

        bool displayStudent20Years();

        int numberStudentSameAgeAndAddress(int age, string address);

        ~Class();

};

#endif