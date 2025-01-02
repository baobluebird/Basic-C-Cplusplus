#ifndef STAFF_H
#define STAFF_H

#include "Employee.h"

class Staff : public Employee {
private:
    string job;

public:
    Staff() : job("") {}

    void enterInformation() override {
        Employee::enterInformation();
        cout << "Enter job: ";
        cin >> job;
    }

    void displayInformation() override {
        cout << "--------- Staff Information ---------" << endl;
        Employee::displayInformation();
        cout << "Job: " << job << endl;
    }
};

#endif
