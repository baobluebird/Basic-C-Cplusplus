#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int age;
    string position;

public:
    Employee() : name("Unknown"), age(0), position("Unassigned") {}

    Employee(string n, int a, string p) : name(n), age(a), position(p) {}

    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setPosition(string p) { position = p; }

    string getName() const { return name; }
    int getAge() const { return age; }
    string getPosition() const { return position; }
};

#endif
