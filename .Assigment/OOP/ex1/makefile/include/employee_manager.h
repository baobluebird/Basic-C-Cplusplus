#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H

#include "employee.h"
#include "staff.h"
#include "engineer.h"
#include "worker.h"
enum class EmployeeType {
    Worker = 1,
    Staff,
    Engineer
};
class EmployeeManager {
    private:
        vector<shared_ptr<Employee>> employeeList;
    public:
        void addEmployee(shared_ptr<Employee>);

        void addEmployeeByType(EmployeeType);

        void searchByName(string);

        void displayAll();

};

#endif