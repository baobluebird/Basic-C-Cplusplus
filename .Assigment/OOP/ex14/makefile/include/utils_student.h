#ifndef UTILS_STUDENT_H
#define UTILS_STUDENT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <regex>
#include <memory>
#include <iomanip>
#include <limits>
#include <fstream>
#include <sstream>

using namespace std;

class InvalidFullNameException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid name. Name must not contain numbers or special characters (Minimum 3 characters)!";
    }
};
class InvalidDOBException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid date format!";
    }
};

class InvalidPhoneNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid phone number! Must be starts with 0 and contains no characters";
    }
};

#endif