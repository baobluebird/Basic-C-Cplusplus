#include "fresher.h"
#include "utils_employees.h"

Fresher::Fresher() : Graduation_date(""), Graduation_rank(""), Education(""){
    type = employeeType::Fresher;
}

Fresher::Fresher(string fullName, string birthDay, string phone, string email, string Graduation_date, string Graduation_rank, string Education)
    : Employee(fullName, birthDay, phone, email, employeeType::Fresher), Graduation_date(Graduation_date), Graduation_rank(Graduation_rank), Education(Education){
    this->type = employeeType::Fresher;
}

string Fresher::getType(){
    return "Fresher";
}

void Fresher::detailEmployee(){
    displayBasicInfo();
    cout << left
         << setw(26) << Graduation_date
         << setw(27) << Graduation_rank
         << setw(30) << Education
         << endl;
    displayCertificates();
}

void Fresher::inputGraduationDate(bool isInput){
    while (true) {
        try {
            isInput == true ? cout << "Enter Graduation Date: " : cout << "Enter new Graduation Date: ";
            cin >> this->Graduation_date;
            if (!isValidDate(this->Graduation_date)) {
                throw DateException();
            }
            break;
        }
        catch (const DateException& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
}

void Fresher::inputGraduationRank(bool isInput){
    while (true) {
        try {
            isInput == true ? cout << "Enter Graduation Rank: " : cout << "Enter new Graduation Rank: ";
            cin.ignore();
            getline(cin, this->Graduation_rank);
            if (!isValidString(this->Graduation_rank)) {
                throw MustBeStringException();
            }
            break;
        }
        catch (const MustBeStringException& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
}

void Fresher::inputEducation(bool isInput){
    while (true) {
        try {
            isInput == true ? cout << "Enter Education: " : cout << "Enter new Education: ";
            getline(cin, this->Education);
            if (!isValidString(this->Education)) {
                throw MustBeStringException();
            }
            break;
        }
        catch (const MustBeStringException& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
}

void Fresher::inputEmployee(){
    Employee::inputEmployee();
    inputGraduationDate(true);
    inputGraduationRank(true);
    inputEducation(true);
}

void Fresher::editEmployee(){
    Employee::editEmployee();
    int choice;
    while (true) {
        detailEmployee();
        cout << "Select the field to edit:\n";
        cout << "6. Graduation Date\n";
        cout << "7. Graduation Rank\n";
        cout << "8. Education\n";
        cout << "0. Finish Editing\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case EditGraduationDate: {  
                inputGraduationDate(false);
                break;
            }
            case EditGraduationRank: {  
                inputGraduationRank(false);
                break;
            }
            case EditEducation: {  
                inputEducation(false);
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

