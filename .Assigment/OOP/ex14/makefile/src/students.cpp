#include "students.h"

bool isValidDOB(const string& birthday) {
    regex pattern(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\d{4}$)"); 
    if (!regex_match(birthday, pattern)) return false;
    int day, month, year;
    sscanf(birthday.c_str(), "%d/%d/%d", &day, &month, &year);
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        daysInMonth[2] = 29;
    }
    return day <= daysInMonth[month];
}

bool isValidPhone(const string& phone) {
    regex pattern(R"(^0\d{9}$)"); 
    return regex_match(phone, pattern);
}

bool isValidFullName(const string& fullName) {
    regex pattern(R"(^[A-Za-zÀ-ỹ ]{3,}$)");
    return regex_match(fullName, pattern);
}

Student::Student(string fullName, string doB, string sex, string phoneNumber, string universityName, string gradeLevel){
    if (!isValidFullName(fullName)) {
        throw InvalidFullNameException();
    }
    if (!isValidDOB(doB)) {
        throw InvalidDOBException();
    }
    if (!isValidPhone(phoneNumber)) {
        throw InvalidPhoneNumberException();
    }
    this->fullName = fullName;
    this->doB = doB;
    this->sex = sex;
    this->phoneNumber = phoneNumber;
    this->universityName = universityName;
    this->gradeLevel = gradeLevel;
}

string Student::getFullName(){ 
    return this->fullName; 
}

string Student::getPhoneNumber(){ 
    return this->phoneNumber; 
}

float Student::getGPA() {
    return 0.0f;
}

int Student::getEnglishScore() {
    return 0;
}

float Student::getEntryTestScore() {
    return 0.0f;
}

void Student::ShowMyInfor(){
        cout << left << setw(20) << this->fullName
     << setw(15) << this->doB
     << setw(10) << this->sex
     << setw(15) << this->phoneNumber
     << setw(20) << this->universityName
     << setw(10) << this->gradeLevel;
}

Student::~Student() {}