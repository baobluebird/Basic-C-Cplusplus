#include "part_time_student.h"

PartTimeStudent::PartTimeStudent() : linkedLocation("") {}

PartTimeStudent::PartTimeStudent(string studentID, string fullName, string dob, int yearEnrolled, float entryScore, string linkedLocation)
    : Student(studentID, fullName, dob, yearEnrolled, entryScore), linkedLocation(linkedLocation) {}

bool PartTimeStudent::isRegular(){
    return false;
}

void PartTimeStudent::inputLinkedLocation(){
    while(true){
        try{
            cout << "Enter Linked Location: ";
            cin.ignore();
            getline(cin, linkedLocation);
            if(!isValidString(linkedLocation)){
                throw MustBeStringException();
            }
            break;
        }catch(const MustBeStringException &e){
            cerr << "Error: " << e.what() << endl;
        }
    }
}

void PartTimeStudent::inputStudent(){
    Student::inputStudent();
    inputLinkedLocation();
}

void PartTimeStudent::displayStudent(){
    cout << left << setw(20) << "Part-Time Student";
    Student::displayStudent();
    cout << left << setw(20) << "Linked Location: " << linkedLocation << endl;
    displayStudyResults();
}


string PartTimeStudent::getLinkedLocation(){
    return linkedLocation;
}