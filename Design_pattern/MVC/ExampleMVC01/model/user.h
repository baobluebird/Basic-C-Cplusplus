#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    std::string name;
    int age;

    User(std::string n, int a) : name(n), age(a) {}
};

#endif
