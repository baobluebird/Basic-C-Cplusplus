#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H

#include "employee.h"
#include <vector>

class EmployeeManager {
    private:
        vector<Employee*> employeeList;
    public:
        void addEmployee(Employee* );

        void searchByName(string);

        void displayAll();

        ~EmployeeManager();
};

#endif