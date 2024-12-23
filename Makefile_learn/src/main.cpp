
#include "employee_manager.h"
#include "staff.h"
#include "worker.h"
#include "engineer.h"

int main() {
    EmployeeManager manager;
    int choice;

    while(1) {
        cout << "------- Menu -------" << endl;
        cout << "1. Add employee" << endl;
        cout << "2. Search employee by name" << endl;
        cout << "3. Display all employees" << endl;
        cout << "0. Exit program" << endl;
        cin >> choice;

        if(choice == 0) {
            break;
        }

        switch (choice) {
            case 1: {
                cout << "1. Add Worker" << endl;
                cout << "2. Add Staff" << endl;
                cout << "3. Add Engineer" << endl;
                int type; 
                cin >> type;
                
                Employee* employee;
                switch (type) {
                    case 1: {
                        cout << "Number of workers to add: ";
                        int num;
                        cin >> num;
                        for(int i = 0; i < num; ++i) {
                            cout << "Enter information for worker " << i + 1 << ":" << endl;
                            employee = new Worker();
                            employee->enterInformation();
                            manager.addEmployee(employee);
                        }
                        break;
                    }
                    case 2: {
                        cout << "Number of staff to add: ";
                        int num;
                        cin >> num;
                        for(int i = 0; i < num; ++i) {
                            cout << "Enter information for staff " << i + 1 << ":" << endl;
                            employee = new Staff();
                            employee->enterInformation();
                            manager.addEmployee(employee);
                        }
                        break;
                    }
                    case 3: {
                        cout << "Number of engineers to add: ";
                        int num;
                        cin >> num;
                        for(int i = 0; i < num; ++i) {
                            cout << "Enter information for engineer " << i + 1 << ":" << endl;
                            employee = new Engineer();
                            employee->enterInformation();
                            manager.addEmployee(employee);
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 2: {
                string name;
                cout << "Enter employee's name to search: ";
                cin >> name;
                manager.searchByName(name);
                break;
            }
            case 3: {
                cout << "--------- All Employees ---------" << endl;
                manager.displayAll();
                break;
            }
            default:
                break;
        }
    }

    return 0;
}