#include "employees_manager.h"
#include "utils_employees.h"

int main() {
    EmployeeManager manager;
    int choice;

    while (1) {
        try {
            cout << "------- Menu -------" << endl;
            cout << "1. Add Employee" << endl;
            cout << "2. Edit employee by id" << endl;
            cout << "3. Delete employee by id" << endl;
            cout << "4. Display all employee" << endl;
            cout << "5. Display all experience" << endl;
            cout << "6. Display all fresher" << endl;
            cout << "7. Display all intern" << endl;
            cout << "0. Exit program" << endl;
            cout << "Your choice: ";
            
            cin >> choice;

            if (cin.fail()) {  
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                throw MenuException();
            }

            switch (choice) {
                case AddEmployee: {
                    int typeInput;
                    string input;
                    bool check = false;

                    while (!check) {
                        try {
                            cout << "0. Add Experience" << endl;
                            cout << "1. Add Fresher" << endl;
                            cout << "2. Add Intern" << endl;
                            cout << "Enter \"exit\" to back to menu" << endl;
                            cout << "Enter your choice: ";
                            cin >> input;

                            if(input == "exit"){
                                cout << "Returning to the main menu..." << endl;
                                break;
                            }

                            if (!regex_match(input, regex("[0-2]"))) {
                                throw MenuAddEmployeeException();
                            }

                            typeInput = stoi(input);
                            employeeType type = static_cast<employeeType>(typeInput);
                            manager.addEmployeeByType(type);
                            check = true;  
                        }
                        catch (const MenuAddEmployeeException& e) {
                            cerr << "Error: " << e.what() << endl;
                        }
                    }
                    break;
                }
                case EditEmployee: {
                    int id;
                    cout << "Enter employee's id to edit: ";
                    cin >> id;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw MenuException();
                    }

                    manager.editEmployeeById(id);
                    break;
                }
                case DeleteEmployee: {
                    int id;
                    cout << "Enter employee's id to delete: ";
                    cin >> id;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw MenuException();
                    }

                    manager.deleteEmployeeById(id);
                    break;
                }
                case DisplayEmployee: {
                    cout << "--------- All Employees ---------" << endl;
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
                case Exit:
                    cout << "Exiting program..." << endl;
                    return 0;
                default:
                    throw MenuException();
            }
        } catch (const MenuException& e) {
            cerr << "Error: " << e.what() << endl;
        } catch (const exception& e) {
            cerr << "Unexpected Error: " << e.what() << endl;
        }
    }

    return 0;
}