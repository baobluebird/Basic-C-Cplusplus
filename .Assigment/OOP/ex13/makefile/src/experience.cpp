#include "experience.h"
#include "utils_employees.h"

Experience::Experience() : ExpInYear(0), ProSkill(""){
    type = employeeType::Experience;
}

Experience::Experience(string fullName, string birthDay, string phone, string email, int ExpInYear, string ProSkill)
    : Employee(fullName, birthDay, phone, email, employeeType::Experience), ExpInYear(ExpInYear), ProSkill(ProSkill){
    this->type = employeeType::Experience;
}

string Experience::getType(){
    return employeeTypeToString(this->type);
}

void Experience::detailEmployee(){
    displayBasicInfo();
    cout << left
         << setw(26) << ExpInYear
         << setw(20) << ProSkill
         << endl;
    displayCertificates();
}

void Experience::inputExperienceInYear(bool isInput){
    while (true) {
        try {
            isInput == true ? cout << "Enter Experience In Year: " : cout << "Enter new Experience In Year: ";
            cin >> this->ExpInYear;
            if (cin.fail() || ExpInYear < 0) {
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

void Experience::inputProSkill(bool isInput){
    while (true) {
        try {
            isInput == true ? cout << "Enter Pro Skill: " : cout << "Enter new Pro Skill: ";
            getline(cin, this->ProSkill);
            if (!isValidString(this->ProSkill)) {
                throw MustBeStringException();
            }
            break;
        }
        catch (const MustBeStringException& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
}

void Experience::inputEmployee(){
    Employee::inputEmployee();
    inputExperienceInYear(true);
    cin.ignore();
    inputProSkill(true);
}


void Experience::editEmployee(){
    Employee::editEmployee();
    int choice;
    while (true) {
        detailEmployee();
        cout << "Select the field to edit:\n";
        cout << "6. Experience In Year\n";
        cout << "7. Pro Skill\n";
        cout << "0. Finish Editing\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case EditExpInYear: { 
                inputExperienceInYear(false);
                break;
            }
            case EditProSkill: { 
                cin.ignore();
                inputProSkill(false);
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