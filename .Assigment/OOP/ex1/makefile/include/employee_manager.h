#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H

#include "employee.h"
#include <vector>
#include <memory>

class EmployeeManager {
    private:
        vector<unique_ptr<Employee>> employeeList;
    public:
        void addEmployee(unique_ptr<Employee>);

        void searchByName(string);

        void displayAll();

};

#endif