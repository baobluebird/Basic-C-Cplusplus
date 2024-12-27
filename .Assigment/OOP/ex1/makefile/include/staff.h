#ifndef STAFF_H
#define STAFF_H

#include "employee.h"
class Staff : public Employee {
    private:
        string job;
    public:
        Staff();
        Staff(string , int , string , string , string );

        void enterInformation() override;

        void display() override;
};

#endif