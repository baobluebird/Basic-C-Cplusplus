#include <employee_manager.h>

void EmployeeManager::addEmployee(Employee *employee)
{
    employeeList.push_back(employee);
}

void EmployeeManager::searchByName(string name)
{
    bool found = false;
    for (Employee *employee : employeeList)
    {
        if (employee->getName() == name)
        {
            employee->display();
            found = true;
        }
    }
    if (!found)
    {
        cout << "No employee found with the name: " << name << endl;
    }
}

void EmployeeManager::displayAll()
{
    for (size_t i = 0; i < employeeList.size(); ++i)
    {
        cout << "Employee " << i + 1 << " Information" << endl;
        employeeList[i]->display();
    }
}

EmployeeManager::~EmployeeManager()
{
    for (Employee *employee : employeeList)
    {
        delete employee;
    }
    employeeList.clear();
}
