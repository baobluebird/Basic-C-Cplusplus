#include "intern.h"
#include "utils_employees.h"


Intern::Intern() : Majors(""), Semester(0), University_name(""){
    type = employeeType::Intern;
}

Intern::Intern(string fullName, string birthDay, string phone, string email, string Majors, int Semester, string University_name)
    : Employee(fullName, birthDay, phone, email, employeeType::Intern), Majors(Majors), Semester(Semester), University_name(University_name){
    this->type = employeeType::Intern;
}

string Intern::getType(){
    return employeeTypeToString(this->type);
}

void Intern::detailEmployee(){
    displayBasicInfo();
    cout << left
         << setw(20) << Majors
         << setw(20) << Semester
         << setw(30) << University_name
         << endl;
    displayCertificates();
}

void Intern::inputMajors(bool isInput){
    while (true) {
        try {
            isInput == true ? cout << "Enter Majors: " : cout << "Enter new Majors: ";
            getline(cin, this->Majors);
            if (!isValidString(this->Majors)) {
                throw MustBeStringException();
            }
            break;
        }
        catch (const MustBeStringException& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
}

void Intern::inputSemester(bool isInput){
    while (true) {
        try {
            isInput == true ? cout << "Enter Semester: " : cout << "Enter new Semester: ";
            cin >> this->Semester;
            if (cin.fail() || Semester < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw MustBeNumberException();
            }
            break;
        }
        catch (const MustBeNumberException& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
}

void Intern::inputUniversityName(bool isInput){
    while (true) {
        try {
            isInput == true ? cout << "Enter University Name: " : cout << "Enter new University Name: ";
            getline(cin, this->University_name);
            if (!isValidString(this->University_name)) {
                throw MustBeStringException();
            }
            break;
        }
        catch (const MustBeStringException& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
}


void Intern::inputEmployee(){
    Employee::inputEmployee();
    inputMajors(true);
    inputSemester(true);
    cin.ignore();
    inputUniversityName(true);
}

void Intern::editEmployee(){
    Employee::editEmployee();  
    int choice;
    while (true) {
        detailEmployee();
        cout << "Select the field to edit:\n";
        cout << "6. Majors\n";
        cout << "7. Semester\n";
        cout << "8. University Name\n";
        cout << "0. Finish Editing\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case EditMajors: {  
                cin.ignore();
                inputMajors(false);
                break;
            }
            case EditSemester: {  
                inputSemester(false);
                break;
            }
            case EditUniversityName: {  
                cin.ignore();
                inputUniversityName(false);
                break;
            }
            case FinishEdit:
                cout << "Finished editing.\n";
                return;
            default:
                cout << "Invalid choice! Please select again.\n";
        }
    }
}