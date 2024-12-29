#include "fresher.h"

Fresher::Fresher() : Graduation_date(""), Graduation_rank(""), Education(""){
    type = employeeType::Fresher;
}

Fresher::Fresher(string fullName, string birthDay, int phone, string email, string Graduation_date, string Graduation_rank, string Education)
    : Employee(fullName, birthDay, phone, email, employeeType::Fresher), Graduation_date(Graduation_date), Graduation_rank(Graduation_rank), Education(Education){
    this->type = employeeType::Fresher;
}

void Fresher::detailEmployee(){
    cout << left
         << setw(10) << getId()
         << setw(20) << Employee::employeeTypeToString(this->type)
         << setw(20) << getFullName()
         << setw(15) << getBirthDay()
         << setw(15) << getPhone()
         << setw(25) << getEmail()
         << setw(20) << Graduation_date
         << setw(20) << Graduation_rank
         << setw(30) << Education
         << endl;
    displayCertificates();
}

void Fresher::inputEmployee(){
    Employee::inputEmployee();
    cout << "Enter Graduation Date: ";
    cin >> this->Graduation_date;
    cout << "Enter Graduation Rank: ";
    cin >> this->Graduation_rank;
    cout << "Enter Education: ";
    cin >> this->Education;
}

string Fresher::getType(){
    return Employee::employeeTypeToString(type);
}