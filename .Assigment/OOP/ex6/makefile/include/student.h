#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iomanip> 
#include <memory>
using namespace std;

class Student{
    private:
        string name;
        int age;
        string address;
    public:
        Student();

        int getAge();

        string getAddress();

        void inputInfoStudent();

        void displayInfoStudent();
        
        ~Student();
};

#endif