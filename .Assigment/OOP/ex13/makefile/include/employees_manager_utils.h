#ifndef EMPLOYEE_MANAGER_UTILS_H
#define EMPLOYEE_MANAGER_UTILS_H
#include "employees_manager.h"
#include "experience.h"
#include "fresher.h"
#include "intern.h"
#define AddEmployee 1
#define EditEmployee 2
#define DeleteEmployee 3
#define DisplayEmployee 4
#define DisplayExperience 5
#define DisplayFresher 6
#define DisplayIntern 7
#define SearchByType 8

void addExperience(EmployeeManager&);

void addFresher(EmployeeManager&);

void addIntern(EmployeeManager&);

#endif