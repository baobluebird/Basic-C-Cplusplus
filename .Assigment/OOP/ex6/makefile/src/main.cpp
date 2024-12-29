#include "school.h"

int main() {
    School school;
    int choice;

    while(1) {
        cout << "------- Menu -------" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display all student under 20 years old" << endl;
        cout << "3. Number student have same age and address" << endl;
        cout << "0. Exit program" << endl;
        cin >> choice;

        if(choice == 0) {
            break;
        }

        switch (choice) {
            case AddStudent: {
                cout << "--------- Add Student ---------" << endl;
                school.addClass();
                break;
            }
            case DisplayStudent20Years: {
                cout << "--------- All Student Under 20 Years Old ---------" << endl;
                school.displayStudent20Years();
                break;
            }
            case FindStudentSameAgeAndAddress: {
                int age; string address;
                cout << "Enter school's age to find: ";
                cin >> age;
                cout << "Enter school's address to find: ";
                cin >> address;
                school.findStudentSameAgeAndAddress(age, address);
                break;
            }
            default:
                break;
        }
    }

    return 0;
}
