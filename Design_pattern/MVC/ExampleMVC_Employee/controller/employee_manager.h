#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include "../model/Worker.h"
#include "../model/Engineer.h"
#include "../model/Staff.h"
#include <vector>
#include <memory>

class EmployeeManager {
private:
    vector<shared_ptr<Employee>> employeeList;

public:
    void addEmployee(shared_ptr<Employee> employee) {
        employeeList.push_back(employee);
    }

    void searchByName(string name) {
        bool found = false;
        for (auto& employee : employeeList) {
            if (employee->getName() == name) {
                employee->displayInformation();
                found = true;
            }
        }
        if (!found) {
            cout << "No employee found with the name: " << name << endl;
        }
    }

    void displayAll() {
        for (size_t i = 0; i < employeeList.size(); ++i) {
            cout << "Employee " << i + 1 << " Information" << endl;
            employeeList[i]->displayInformation();
        }
    }
};

#endif
