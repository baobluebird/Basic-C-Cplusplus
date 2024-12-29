#include "student.h"

Student::Student() : name(""), age(0), address("") {}

int Student::getAge(){
    return this->age;
}

string Student::getAddress(){
    return this->address;
}

void Student::inputInfoStudent(){
    cout << "Enter Name: ";
    cin >> this->name;
    cout << "Enter age: ";
    cin >> this->age;
    cout << "Enter address: ";
    cin >> this->address;
}

void Student::displayInfoStudent(){
    cout << setw(16) << this->name << setw(10) << this->age << setw(10) << this->address << endl;
}

Student::~Student() {}