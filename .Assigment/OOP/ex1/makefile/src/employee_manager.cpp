#include <employee_manager.h>

void EmployeeManager::addEmployee(shared_ptr<Employee> employee){
    employeeList.push_back(employee);
}

void EmployeeManager::addEmployeeByType(EmployeeType type){
    int num;
    cout << "Number of employees to add: ";
    cin >> num;
    cin.ignore();
    string typeStr;

    for (int i = 0; i < num; ++i)
    {
        shared_ptr<Employee> employee;
        switch (type)
        {
        case EmployeeType::Worker:
            typeStr = "Worker";
            employee = make_shared<Worker>();
            break;
        case EmployeeType::Staff:
            typeStr = "Staff";
            employee = make_shared<Staff>();
            break;
        case EmployeeType::Engineer:
            typeStr = "Engineer";
            employee = make_shared<Engineer>();
            break;
        default:
            cout << "Invalid employee type." << endl;
            return;
        }

        cout << "Enter information for " << typeStr << " " << i + 1 << ":" << endl;
        employee->enterInformation();
        addEmployee(employee);
    }
}

void EmployeeManager::searchByName(string name){
    bool found = false;
    for (auto &employee : employeeList)
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

void EmployeeManager::displayAll(){
    for (size_t i = 0; i < employeeList.size(); ++i)
    {
        cout << "Employee " << i + 1 << " Information" << endl;
        employeeList[i]->displayInformation();
    }
}
