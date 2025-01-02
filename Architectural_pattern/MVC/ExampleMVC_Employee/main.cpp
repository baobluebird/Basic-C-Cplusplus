#include "model/Employee.h"
#include "views/employee_views.h"
#include "controller/employee_manager.h"

int main() {
    Employee model("John Doe", 30, "Software Engineer");
    EmployeeView view;

    EmployeeController controller(model, view);

    controller.updateView();

    controller.setEmployeeName("Jane Smith");
    controller.setEmployeeAge(28);
    controller.setEmployeePosition("Project Manager");

    controller.updateView();

    return 0;
}
