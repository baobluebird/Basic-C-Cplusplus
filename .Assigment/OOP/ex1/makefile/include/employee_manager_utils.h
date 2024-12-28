#ifndef EMPLOYEE_MANAGER_UTILS_H
#define EMPLOYEE_MANAGER_UTILS_H

#include "employee_manager.h"
#include "staff.h"
#include "worker.h"
#include "engineer.h"

#define AddEmployee 1
#define SearchEmployeeByName 2
#define DisplayEmployee 3

using namespace std;
enum class EmployeeType {
    Worker = 1,
    Staff,
    Engineer
};

void addWorker(EmployeeManager &manager);
void addStaff(EmployeeManager &manager);

void addEngineer(EmployeeManager &manager);

#endif
