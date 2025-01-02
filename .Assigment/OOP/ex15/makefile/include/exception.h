#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>

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

#endif