#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H

#include "employees.h"

class EmployeeManager{
    private:
        vector<shared_ptr<Employee>> listEmployees;
    public:

        void addEmployee(shared_ptr<Employee>);

        void addEmployeeByType(employeeType);

        void editEmployeeById(int);

        bool deleteEmployeeById(int );

        void displayEmployee();

        void displayIntern();

        void displayExperience();

        void displayFresher();

};

#endif