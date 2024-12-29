#include "household.h"

Household::Household() : numMember(0), address("") {}

void Household::inputInfoHousehold(){
    cout << "Enter Number member: ";
    cin >> this->numMember;
    cout << "Enter Address: ";
    cin >> this->address;
    for (int i = 0; i < this->numMember; ++i)
    {
        cout << "Enter information of person " << i + 1 << ":" << endl;
        shared_ptr<Person> person = make_shared<Person>();
        person->inputInfoPerson();
        listPerson.push_back(person);
    }
}

void Household::displayInfoHousehold(){
    cout << "Number Member: " << this->numMember << endl;
    cout << "Address: " << this->address << endl;
    cout << left
         << setw(10) << "ID Number"
         << setw(16) << "Name"
         << setw(10) << "Age"
         << setw(10) << "Job"
         << endl;
    cout << string(65, '-') << endl;
    for (shared_ptr<Person> person : listPerson)
    {
        person->displayInfoPerson();
    }
    cout << string(65, '-') << endl;
}

Household::~Household(){
    cout << "Destructor of Household have address: " << address << endl;
}