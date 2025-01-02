#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    int age;
    string gender;
    string address;

public:
    Employee() : name(""), age(0), gender(""), address("") {}

    Employee(string name, int age, string gender, string address) 
        : name(name), age(age), gender(gender), address(address) {}

    virtual void enterInformation() {
        cout << "Enter employee's name: ";
        cin >> name;
        cout << "Enter employee's age: ";
        cin >> age;
        cout << "Enter employee's gender: ";
        cin >> gender;
        cout << "Enter employee's address: ";
        cin >> address;
    }

    string getName() { return name; }

    virtual void displayInformation() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Address: " << address << endl;
    }

    virtual ~Employee() {
        cout << "Destructor of Employee: " << name << endl;
    }
};

#endif
