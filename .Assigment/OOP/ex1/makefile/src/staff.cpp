#include <staff.h>

Staff::Staff() : job("") {}
Staff::Staff(string name, int age, string gender, string address, string job)
    : Employee(name, age, gender, address), job(job) {}

void Staff::enterInformation(){
    Employee::enterInformation();
    cout << "Enter job: ";
    cin >> job;
}

void Staff::display(){
    cout << "--------- Staff Information ---------" << endl;
    Employee::display();
    cout << "Job: " << this->job << endl;
}