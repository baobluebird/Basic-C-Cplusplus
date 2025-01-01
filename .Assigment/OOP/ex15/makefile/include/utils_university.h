#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <regex>
#include <map>
#include <stdexcept>
#include <iomanip>
#include <limits>

//define menu
#define AddStudent 1
#define CheckRegularStudent 2
#define GetAverageScore 3
#define DisplayTotalRegularStudents 4
#define FindStudentHighestEntryScore 5
#define ListPartTimeStudentsByLocation 6
#define ListStudentsAbove8InLatestSemester 7
#define FindStudentHighestSemesterScore 8
#define SortStudentsByTypeAndYear 9
#define CountStudentsByYear 10
#define DisplayStudents 11
#define Exit 0

using namespace std;

class FullNameException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid name. Name must not contain numbers or special characters (Minimum 3 characters)!";
    }
};

class DateException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid date format!";
    }
};

class YearException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid year format!";
    }
};

class ScoreException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid score format!";
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

class MenuException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid menu choice! Please enter a valid number of 0 -> 8.";
    }
};