#include <employee.h>

Employee::Employee() : name(""), age(0), gender(""), address(""){}

Employee::Employee(string name, int age, string gender, string address){
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->address = address;
}

void Employee::enterInformation(){
    cout << "Enter employee's name: ";
    cin >> name;
    cout << "Enter employee's age: ";
    cin >> age;
    cout << "Enter employee's gender: ";
    cin >> gender;
    cout << "Enter employee's address: ";
    cin >> address;
}

string Employee::getName(){
    return this->name;
}

void Employee::displayInformation(){
    cout << "Name: " << this->name <<endl;
    cout << "Age: " << this->age <<endl;
    cout << "Gender: " << this->gender <<endl;
    cout << "Address: " << this->address <<endl;
}

Employee::~Employee(){
    cout << "Destructor of Employee: " << this->name << endl;
}