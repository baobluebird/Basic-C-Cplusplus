#include "employees_manager_utils.h"

void addExperience(EmployeeManager& manager){
    int num;
    cout << "Number of Experience to add: ";
    cin >> num;
    for(int i = 0; i < num; ++i){
        cout << "Enter information for experience " << i + 1 << ":" << endl;
        unique_ptr<Employee> employee = make_unique<Experience>();
        employee->inputEmployee();
        manager.addEmployee(move(employee));
    }
}

void addFresher(EmployeeManager& manager){
    int num;
    cout << "Number of Fresher to add: ";
    cin >> num;
    for(int i = 0; i < num; ++i){
        cout << "Enter information for fresher " << i + 1 << ":" << endl;
        unique_ptr<Employee> employee = make_unique<Fresher>();
        employee->inputEmployee();
        manager.addEmployee(move(employee));
    }
}

void addIntern(EmployeeManager& manager){
    int num;
    cout << "Number of Intern to add: ";
    cin >> num;
    for(int i = 0; i < num; ++i){
        cout << "Enter information for intern " << i + 1 << ":" << endl;
        unique_ptr<Employee> employee = make_unique<Intern>();
        employee->inputEmployee();
        manager.addEmployee(move(employee));
    }
}