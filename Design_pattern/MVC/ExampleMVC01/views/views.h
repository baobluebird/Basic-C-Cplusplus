#ifndef USERVIEW_H
#define USERVIEW_H

#include <iostream>
#include <string>

class UserView {
public:
    void printUserDetails(std::string name, int age) {
        std::cout << "User: " << name << "\n";
        std::cout << "Age: " << age << "\n";
    }
};

#endif
