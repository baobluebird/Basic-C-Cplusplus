#ifndef ENGINEER_H
#define ENGINEER_H

#include "Employee.h"

class Engineer : public Employee {
private:
    string major;

public:
    Engineer() : major("") {}

    void enterInformation() override {
        Employee::enterInformation();
        cout << "Enter major: ";
        cin >> major;
    }

    void displayInformation() override {
        cout << "-------- Engineer Information --------" << endl;
        Employee::displayInformation();
        cout << "Major: " << major << endl;
    }
};

#endif
