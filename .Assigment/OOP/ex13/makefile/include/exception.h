#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
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