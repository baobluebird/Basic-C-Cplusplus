
#include "employee_manager_utils.h"

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
            case AddEmployee: {
                cout << "1. Add Worker" << endl;
                cout << "2. Add Staff" << endl;
                cout << "3. Add Engineer" << endl;
                int typeInput; 
                cin >> typeInput;
                EmployeeType type = static_cast<EmployeeType>(typeInput);
                shared_ptr<Employee> employee;
                switch (type) {
                    case EmployeeType::Worker: {
                        addWorker(manager);
                        break;
                    }
                    case EmployeeType::Staff: {
                        addStaff(manager);
                        break;
                    }
                    case EmployeeType::Engineer: {
                        addEngineer(manager);
                        break;
                    }
                    default:
                        cout << "Invalid input" << endl;
                        break;
                }
                break;
            }
            case SearchEmployeeByName: {
                string name;
                cout << "Enter employee's name to search: ";
                cin >> name;
                manager.searchByName(name);
                break;
            }
            case DisplayEmployee: {
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