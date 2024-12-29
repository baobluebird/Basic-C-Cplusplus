#ifndef EMPLOYYE_MANAGER_H
#define EMPLOYYE_MANAGER_H

#include "employees.h"
class EmployeeManager{
    private:
        vector<unique_ptr<Employee>> listEmployees;
    public:

        void addEmployee(unique_ptr<Employee> );

        void editEmployeeById(int);

        bool deleteEmployeeById(int );

        void displayEmployee();

        void displayIntern();

        void displayExperience();

        void displayFresher();

        void searchEmployeeByType(string);
};

#endif