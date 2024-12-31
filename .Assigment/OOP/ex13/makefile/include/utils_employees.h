#ifndef EMPLOYEE_MANAGER_UTILS_H
#define EMPLOYEE_MANAGER_UTILS_H
#include <iostream>
//define menu
#define AddEmployee 1
#define EditEmployee 2
#define DeleteEmployee 3
#define DisplayEmployee 4
#define DisplayExperience 5
#define DisplayFresher 6
#define DisplayIntern 7
#define Exit 0
//define editEmployee
#define EditName 1
#define EditBirthDay 2
#define EditPhone 3
#define EditEmail 4
#define EditCertificates 5
#define FinishEdit 0
//define editEmployee Experience
#define EditExpInYear 6
#define EditProSkill 7
//define editEmployee Fresher
#define EditGraduationDate 6
#define EditGraduationRank 7
#define EditEducation 8
//define editEmployee Intern
#define EditMajors 6
#define EditSemester 7
#define EditUniversityName 8
//define editEmployee Certificate
#define EditCerID 1
#define EditCerName 2
#define EditCerRank 3
#define EditCerDate 4

using namespace std;

class DateException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid date format!";
    }
};

class PhoneException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid phone number! Must be starts with 0 and contains no characters";
    }
};

class EmailException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid email format!";
    }
};

class FullNameException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid name. Name must not contain numbers or special characters (Minimum 3 characters)!";
    }
};

class MenuException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid menu choice! Please enter a valid number of 0 -> 8.";
    }
};

class MenuAddEmployeeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid menu choice! Please enter a valid number of 0 -> 2.";
    }
};

class MustBeNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid menu choice! Please enter a valid number.";
    }
};

class MustBeStringException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid input! Please enter a valid string (no numbers or empty input).";
    }
};

#endif