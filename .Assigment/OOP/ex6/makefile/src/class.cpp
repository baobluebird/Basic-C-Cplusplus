#include "class.h"

Class::Class() : nameClass("") {}

void Class::inputInfoClass(){
    int numberStudent;
    cout << "Enter Number Student: ";
    cin >> numberStudent;
    cout << "Enter Name Class: ";
    cin >> this->nameClass;
    for (int i = 0; i < numberStudent; ++i){
        cout << "Enter information of person " << i + 1 << ":" << endl;
        shared_ptr<Student> student = make_shared<Student>();
        student->inputInfoStudent();
        listStudents.push_back(student);
    }
}

void Class::displayInfoClass(){
    cout << "Name Class: " << this->nameClass << endl;
    cout << left
         << setw(16) << "Name"
         << setw(10) << "Age"
         << setw(10) << "Address"
         << endl;
    cout << string(65, '-') << endl;
    for (shared_ptr<Student> person : listStudents){
        person->displayInfoStudent();
    }
    cout << string(65, '-') << endl;
}

bool Class::displayStudent20Years(){
    bool found = false;
    cout << string(65, '-') << endl;
    cout << "Name Class: " << this->nameClass << endl;
    cout << left
         << setw(16) << "Name"
         << setw(10) << "Age"
         << setw(10) << "Address"
         << endl;
    for (shared_ptr<Student> student : listStudents){
        if (student->getAge() == 20){
            student->displayInfoStudent();
            found = true;
        }
    }
    cout << string(65, '-') << endl;
    return found;
}

int Class::numberStudentSameAgeAndAddress(int age, string address){
    int num = 0;

    for (shared_ptr<Student> student : listStudents){
        if (student->getAge() == age && student->getAddress() == address){
            num++;
        }
    }
    return num;
}

Class::~Class(){
    cout << "Destructor of Household have address: " << nameClass << endl;
}
