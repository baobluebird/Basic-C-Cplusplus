#include "person.h"
set<int> Person::listIdNumber;

Person::Person() : idNumber(0), name(""), age(0), job("") {}

void Person::inputInfoPerson(){
    int temp;
    cout << "Enter ID Number: ";
    cin >> temp;
    while (listIdNumber.find(temp) != listIdNumber.end())
    {
        cout << "This number already exists. Please enter another ID Number: ";
        cin >> temp;
    }
    listIdNumber.insert(temp);
    this->idNumber = temp;
    cout << "Enter Name: ";
    cin >> this->name;
    cout << "Enter age: ";
    cin >> this->age;
    cout << "Enter job: ";
    cin >> this->job;
}

void Person::displayInfoPerson(){
    cout << setw(10) << this->idNumber << setw(16) << this->name << setw(10) << this->age << setw(10) << this->job << endl;
}

Person::~Person()
{
    cout << "Destructor of Person ID: " << idNumber << endl;
}