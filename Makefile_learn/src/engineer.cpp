#include <engineer.h>

Engineer::Engineer() : major(""){}

Engineer::Engineer(string name, int age, string gender, string address, string major)
    : Employee(name, age, gender, address){}

void Engineer::enterInformation(){
    Employee::enterInformation();
    cout << "Enter major: " << endl;
    cin >> major;
}

void Engineer::display(){
    cout << "-------- Engineer Information --------" << endl;
    Employee::display();
    cout << "Major: " << this->major << endl;
}
