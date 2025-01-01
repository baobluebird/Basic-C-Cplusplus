#include "regular_student.h"

RegularStudent::RegularStudent(string studentID, string fullName, string dob, int yearEnrolled, float entryScore)
    : Student(studentID, fullName, dob, yearEnrolled, entryScore) {}

bool RegularStudent::isRegular(){
    return true;
}

void RegularStudent::displayStudent(){
    cout << left << setw(20) << "Regular Student";
    Student::displayStudent();
    displayStudyResults();
}