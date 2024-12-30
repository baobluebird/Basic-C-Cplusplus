#include "intern.h"

Intern::Intern() : Majors(""), Semester(0), University_name(""){
    type = employeeType::Intern;
}

Intern::Intern(string fullName, string birthDay, string phone, string email, string Majors, int Semester, string University_name)
    : Employee(fullName, birthDay, phone, email, employeeType::Intern), Majors(Majors), Semester(Semester), University_name(University_name){
    this->type = employeeType::Intern;
}

void Intern::detailEmployee(){
    cout << left
         << setw(10) << getId()
         << setw(20) << Employee::employeeTypeToString(this->type)
         << setw(20) << getFullName()
         << setw(15) << getBirthDay()
         << setw(15) << getPhone()
         << setw(20) << getEmail()
         << setw(20) << Majors
         << setw(20) << Semester
         << setw(30) << University_name
         << endl;
    displayCertificates();
}

void Intern::inputEmployee(){
    Employee::inputEmployee();
    cout << "Enter Majors: ";
    cin >> this->Majors;
    cout << "Enter Semester: ";
    cin >> this->Semester;
    cout << "Enter University Name: ";
    cin >> this->University_name;
}

string Intern::getType(){
    return Employee::employeeTypeToString(type);
}