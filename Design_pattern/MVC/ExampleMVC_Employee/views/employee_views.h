#ifndef EMPLOYEEVIEW_H
#define EMPLOYEEVIEW_H

#include <iostream>
#include "../model/employee.h"

class EmployeeView {
public:
    static void display(Employee& employee) {
        employee.displayInformation();
    }
};

#endif
