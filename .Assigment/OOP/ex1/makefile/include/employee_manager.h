#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H

#include "employee.h"
#include <vector>
#include <memory>

class EmployeeManager {
    private:
        vector<shared_ptr<Employee>> employeeList;
    public:
        void addEmployee(shared_ptr<Employee>);

        void searchByName(string);

        void displayAll();

};

#endif