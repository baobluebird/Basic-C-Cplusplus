#include "employees_manager_utils.h"

int main() {
    EmployeeManager manager;
    int choice;

    while(1) {
        cout << "------- Menu -------" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Edit employee by id" << endl;
        cout << "3. Delete employee by id" << endl;
        cout << "4. Display all employee" << endl;
        cout << "5. Display all experience" << endl;
        cout << "6. Display all fresher" << endl;
        cout << "7. Display all intern" << endl;
        cout << "8. Search employee by type" << endl;
        cout << "0. Exit program" << endl;
        cin >> choice;

        if(choice == 0) {
            break;
        }
        switch (choice) {
            case AddEmployee: {
                try{
                    cout << "0. Add Experience" << endl;
                    cout << "1. Add Fresher" << endl;
                    cout << "2. Add Intern" << endl;
                    int typeInput; 
                    cin >> typeInput;
                    employeeType type = static_cast<employeeType>(typeInput);
                    switch (type) {
                        case employeeType::Experience: {
                            addExperience(manager);
                            break;
                        }
                        case employeeType::Fresher: {
                            addFresher(manager);
                            break;
                        }
                        case employeeType::Intern: {
                            addIntern(manager);
                            break;
                        }
                        default:
                            cout << "Invalid choice" << endl;
                            break;
                    }
                    break;
                }catch (const exception& e) {
                        cerr << "Exception: " << e.what() << endl;
                }
                break;
                    
            }
            case EditEmployee: {
                int id;
                cout << "Enter employee's id to edit: ";
                cin >> id;
                manager.editEmployeeById(id);
                break;
            }
            case DeleteEmployee: {
                int id;
                cout << "Enter employee's id to delete: ";
                cin >> id;
                manager.deleteEmployeeById(id);
                break;
            }
            case DisplayEmployee: {
                cout << "--------- All Documents ---------" << endl;
                manager.displayEmployee();
                break;
            }
            case DisplayExperience: {
                cout << "--------- All Experience ---------" << endl;
                manager.displayExperience();
                break;
            }
            case DisplayFresher: {
                cout << "--------- All Fresher ---------" << endl;
                manager.displayFresher();
                break;
            }
            case DisplayIntern: {
                cout << "--------- All Intern ---------" << endl;
                manager.displayIntern();
                break;
            }
            case SearchByType: {
                string type;
                cout << "Enter employee's type to search: ";
                cin >> type;
                manager.searchEmployeeByType(type);
                break;
            }
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}