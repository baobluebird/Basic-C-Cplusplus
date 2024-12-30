#include <employee_manager.h>

void EmployeeManager::addEmployee(unique_ptr<Employee> employee)
{
    employeeList.push_back(move(employee));
}

void EmployeeManager::searchByName(string name)
{
    bool found = false;
    for (auto& employee : employeeList)
    {
        if (employee->getName() == name)
        {
            employee->displayInformation();
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
        employeeList[i]->displayInformation();
    }
}

