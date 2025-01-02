#include "controller/employee_manager.h"

int main() {
    EmployeeManager manager;
    int choice;

    while (1) {
        cout << "------- Menu -------" << endl;
        cout << "1. Add Worker" << endl;
        cout << "2. Add Staff" << endl;
        cout << "3. Add Engineer" << endl;
        cout << "4. Search employee by name" << endl;
        cout << "5. Display all employees" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;

        if (choice == 0) {
            break;
        }

        shared_ptr<Employee> employee;

        switch (choice) {
            case 1:{
                employee = make_shared<Worker>();
                break;
            }
            case 2:{
                employee = make_shared<Staff>();
                break;
            }
                
            case 3:{
                employee = make_shared<Engineer>();
                break;
            }
                
            case 4:{
                string name;
                cout << "Enter employee's name to search: ";
                cin >> name;
                manager.searchByName(name);
                continue;
            }
                
            case 5:{
                manager.displayAll();
                continue;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
                continue;
        }

        employee->enterInformation();
        manager.addEmployee(employee);
    }

    return 0;
}
