#include "employees_manager.h"

void EmployeeManager::addEmployee(unique_ptr<Employee> document){
    if (!Employee::recycledIds.empty())
    {
        int recycleId = *Employee::recycledIds.begin();
        Employee::recycledIds.erase(Employee::recycledIds.begin());
        listEmployees.insert(listEmployees.begin() + (recycleId - 1), move(document));
    }
    else
    {
        listEmployees.push_back(move(document));
    }
}

void EmployeeManager::editEmployeeById(int id){
    int size = Employee::manageId.size();
    if (id < 1 || id > size)
    {
        cout << "ID not found" << endl;
        return;
    }

    listEmployees[id - 1]->editEmployee();
}

bool EmployeeManager::deleteEmployeeById(int id){
    int size = Employee::manageId.size();
    if (id < 1 || id > size)
    {
        cout << "ID not found" << endl;
        return false;
    }

    listEmployees.erase(listEmployees.begin() + (id - 1));

    cout << "Delete successfully" << endl;
    return true;
}

void EmployeeManager::displayEmployee(){
    cout << left
         << setw(10) << "ID"
         << setw(20) << "Employee Type"
         << setw(20) << "Full Name"
         << setw(15) << "BirthDay"
         << setw(15) << "Phone"
         << setw(25) << "Email"
         << setw(20) << "ExpInYear/Grad Date/Majors"
         << setw(20) << "ProSkill/Grad Rank/Semester"
         << setw(30) << "Education/University"
         << endl;
    cout << string(170, '-') << endl;
    for (size_t i = 0; i < listEmployees.size(); ++i)
    {
        unique_ptr<Employee> &doc = listEmployees[i];
        doc->detailEmployee();
    }
    cout << string(170, '-') << endl;
}

void EmployeeManager::displayIntern(){
    cout << left
         << setw(10) << "ID"
         << setw(20) << "Employee Type"
         << setw(20) << "Full Name"
         << setw(15) << "BirthDay"
         << setw(15) << "Phone"
         << setw(25) << "Email"
         << setw(20) << "Majors"
         << setw(20) << "Semester"
         << setw(30) << "University Name"
         << endl;
    cout << string(170, '-') << endl;
    for (size_t i = 0; i < listEmployees.size(); ++i)
    {
        unique_ptr<Employee> &doc = listEmployees[i];
        if (doc->getType() == "Intern")
        {
            doc->detailEmployee();
        }
    }
    cout << string(170, '-') << endl;
}

void EmployeeManager::displayExperience(){
    cout << left
         << setw(10) << "ID"
         << setw(20) << "Employee Type"
         << setw(20) << "Full Name"
         << setw(15) << "BirthDay"
         << setw(15) << "Phone"
         << setw(25) << "Email"
         << setw(20) << "ExpInYear"
         << setw(20) << "ProSkill"
         << endl;
    cout << string(170, '-') << endl;
    for (size_t i = 0; i < listEmployees.size(); ++i)
    {
        unique_ptr<Employee> &doc = listEmployees[i];
        if (doc->getType() == "Experience")
        {
            doc->detailEmployee();
        }
    }
    cout << string(170, '-') << endl;
}

void EmployeeManager::displayFresher(){
    cout << left
         << setw(10) << "ID"
         << setw(20) << "Employee Type"
         << setw(20) << "Full Name"
         << setw(15) << "BirthDay"
         << setw(15) << "Phone"
         << setw(25) << "Email"
         << setw(20) << "Graduation Date"
         << setw(20) << "Graduation Rank"
         << setw(30) << "Education"
         << endl;
    cout << string(170, '-') << endl;
    for (size_t i = 0; i < listEmployees.size(); ++i)
    {
        unique_ptr<Employee> &doc = listEmployees[i];
        if (doc->getType() == "Fresher")
        {
            doc->detailEmployee();
        }
    }
    cout << string(170, '-') << endl;
}

void EmployeeManager::searchEmployeeByType(string type){
    bool found = false;
    for (size_t i = 0; i < listEmployees.size(); ++i)
    {
        unique_ptr<Employee> &doc = listEmployees[i];
        if (doc->getType() == type)
        {
            doc->detailEmployee();
            found = true;
        }
    }
    if (!found)
    {
        cout << "No employee of type " << type << " found." << endl;
    }
}