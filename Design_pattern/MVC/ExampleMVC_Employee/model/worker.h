#ifndef WORKER_H
#define WORKER_H

#include "Employee.h"

class Worker : public Employee {
private:
    int level;

public:
    Worker() : level(0) {}

    void enterInformation() override {
        Employee::enterInformation();
        cout << "Enter level (1-10): ";
        cin >> level;

        while (level < 1 || level > 10) {
            cout << "Level must be between 1 and 10. Please re-enter: ";
            cin >> level;
        }
    }

    void displayInformation() override {
        cout << "---------- Worker Information ----------" << endl;
        Employee::displayInformation();
        cout << "Level: " << level << endl;
    }
};

#endif
