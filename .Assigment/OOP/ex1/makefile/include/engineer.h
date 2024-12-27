#ifndef ENGINEER_H
#define ENGINEER_H

#include <employee.h>

class Engineer : public Employee {
    private:
        string major;
    public:
        Engineer();
        Engineer(string, int, string, string, string);

        void enterInformation() override;

        void display() override;

};

#endif