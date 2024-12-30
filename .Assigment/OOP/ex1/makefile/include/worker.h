#ifndef WORKER_H
#define WORKER_H

#include "employee.h"

class Worker : public Employee {
    private:
        int level;
    public:
        Worker();
        Worker(string , int , string , string , int );

        void enterInformation() override;

        void displayInformation() override;
};

#endif