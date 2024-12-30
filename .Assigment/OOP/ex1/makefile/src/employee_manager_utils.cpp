#include "employee_manager_utils.h"


void addWorker(EmployeeManager &manager) {
    int num;
    cout << "Number of workers to add: ";
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cout << "Enter information for worker " << i + 1 << ":" << endl;
        unique_ptr<Employee> employee = make_unique<Worker>();
        employee->enterInformation();
        manager.addEmployee(move(employee));
    }
}

void addStaff(EmployeeManager &manager) {
    int num;
    cout << "Number of staff to add: ";
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cout << "Enter information for staff " << i + 1 << ":" << endl;
        unique_ptr<Employee> employee = make_unique<Staff>();
        employee->enterInformation();
        manager.addEmployee(move(employee));
    }
}

void addEngineer(EmployeeManager &manager) {
    int num;
    cout << "Number of engineers to add: ";
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cout << "Enter information for engineer " << i + 1 << ":" << endl;
        unique_ptr<Employee> employee = make_unique<Engineer>();
        employee->enterInformation();
        manager.addEmployee(move(employee));
    }
}
