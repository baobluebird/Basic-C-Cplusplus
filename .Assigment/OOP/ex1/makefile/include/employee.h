#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;

class Employee{
    private:
        string name;
        int age;
        string gender;
        string address;
    public:
        Employee();
        Employee(string , int , string , string );

        string getName();

        virtual void enterInformation();
        
        virtual void displayInformation();

        virtual ~Employee();
};

#endif
