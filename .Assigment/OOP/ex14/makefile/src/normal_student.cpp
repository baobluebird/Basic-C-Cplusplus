#include "normal_student.h"

NormalStudent::NormalStudent(string fullName, string doB, string sex, string phoneNumber, string universityName, string gradeLevel, int englishScore, float entryTestScore)
    : Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), englishScore(englishScore), entryTestScore(entryTestScore) {}

void NormalStudent::ShowMyInfor(){
    cout << left << setw(15) << "Normal Student";
    Student::ShowMyInfor();
    cout << setw(10) << englishScore
         << setw(10) << entryTestScore << endl;
}

int NormalStudent::getEnglishScore(){
    return this->englishScore;
}

float NormalStudent::getEntryTestScore(){
    return this->entryTestScore;
}

float NormalStudent::getGPA(){
    return 0.0f;
}

string NormalStudent::getType(){
    return "Normal Student";
}