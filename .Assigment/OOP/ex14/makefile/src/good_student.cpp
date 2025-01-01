#include "good_student.h"

GoodStudent::GoodStudent(string fullName, string doB, string sex, string phoneNumber, string universityName, string gradeLevel, float gpa, string bestRewardName)
        : Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), gpa(gpa), bestRewardName(bestRewardName) {}

void GoodStudent::ShowMyInfor(){
    cout << left << setw(15) << "Good Student";
    Student::ShowMyInfor();
    cout << setw(10) << this->gpa
         << setw(20) << this->bestRewardName << endl;
}

float GoodStudent::getGPA(){
    return this->gpa; 
}

int GoodStudent::getEnglishScore(){
    return 0;
}

float GoodStudent::getEntryTestScore(){
    return 0.0f;
}

string GoodStudent::getType(){
    return "Good Student";
}