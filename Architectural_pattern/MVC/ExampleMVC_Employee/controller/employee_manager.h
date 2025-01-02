#ifndef EMPLOYEECONTROLLER_H
#define EMPLOYEECONTROLLER_H

#include "../model/employee.h"
#include "../views/employee_views.h"

class EmployeeController {
private:
    Employee model;
    EmployeeView view;

public:
    EmployeeController(Employee m, EmployeeView v) : model(m), view(v) {}

    void setEmployeeName(string name) { model.setName(name); }
    void setEmployeeAge(int age) { model.setAge(age); }
    void setEmployeePosition(string position) { model.setPosition(position); }

    string getEmployeeName() const { return model.getName(); }
    int getEmployeeAge() const { return model.getAge(); }
    string getEmployeePosition() const { return model.getPosition(); }

    void updateView() { view.displayEmployee(model); }
};

#endif
