#include "experience.h"

Experience::Experience() : ExpInYear(0), ProSkill("")
{
    type = employeeType::Experience;
}

Experience::Experience(string fullName, string birthDay, int phone, string email, int ExpInYear, string ProSkill)
    : Employee(fullName, birthDay, phone, email, employeeType::Experience), ExpInYear(ExpInYear), ProSkill(ProSkill)
{
    this->type = employeeType::Experience;
}

void Experience::detailEmployee(){
    cout << left
         << setw(10) << getId()
         << setw(20) << Employee::employeeTypeToString(this->type)
         << setw(20) << getFullName()
         << setw(15) << getBirthDay()
         << setw(15) << getPhone()
         << setw(25) << getEmail()
         << setw(20) << ExpInYear
         << setw(20) << ProSkill
         << endl;
    displayCertificates();
}

void Experience::inputEmployee(){
    Employee::inputEmployee();
    cout << "Enter Experience In Year: ";
    cin >> this->ExpInYear;
    cout << "Enter Pro Skill: ";
    cin >> this->ProSkill;
}

string Experience::getType(){
    return Employee::employeeTypeToString(type);
}