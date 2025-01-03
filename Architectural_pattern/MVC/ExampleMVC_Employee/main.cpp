#include "model/Employee.h"
#include "views/employee_views.h"
#include "controller/employee_manager.h"

void displayMenu() {
    cout << "----------- Employee Management -----------" << endl;
    cout << "1. Display Employee Information" << endl;
    cout << "2. Update Employee Name" << endl;
    cout << "3. Update Employee Age" << endl;
    cout << "4. Update Employee Position" << endl;
    cout << "0. Exit Program" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Employee model("John Doe", 30, "Software Engineer");
    EmployeeView view;
    EmployeeController controller(model, view);

    int choice;
    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }

        switch (choice) {
            case 1: 
                controller.updateView();
                break;

            case 2: { 
                string newName;
                cout << "Enter new employee name: ";
                cin.ignore(); 
                getline(cin, newName);
                controller.setEmployeeName(newName);
                cout << "Employee name updated successfully!" << endl;
                break;
            }

            case 3: { 
                int newAge;
                cout << "Enter new employee age: ";
                cin >> newAge;
                controller.setEmployeeAge(newAge);
                cout << "Employee age updated successfully!" << endl;
                break;
            }

            case 4: { 
                string newPosition;
                cout << "Enter new employee position: ";
                cin.ignore(); 
                getline(cin, newPosition);
                controller.setEmployeePosition(newPosition);
                cout << "Employee position updated successfully!" << endl;
                break;
            }

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}