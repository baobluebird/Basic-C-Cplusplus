#ifndef EMPLOYEEVIEW_H
#define EMPLOYEEVIEW_H

#include <iostream>
#include "../model/Employee.h"

class EmployeeView {
public:
    void displayEmployee(const Employee& emp) {
        cout << "------- Employee Details -------" << endl;
        cout << "Name: " << emp.getName() << endl;
        cout << "Age: " << emp.getAge() << endl;
        cout << "Position: " << emp.getPosition() << endl;
        cout << "--------------------------------" << endl;
    }
};

#endif
