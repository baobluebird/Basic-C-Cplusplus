#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iomanip> 
#include <memory>
using namespace std;

class Person{
    private:
        int idNumber;
        string name;
        int age;
        string job;
        static set<int> listIdNumber;
    public:
        Person();
        void inputInfoPerson();
        void displayInfoPerson();
        ~Person();
};

#endif