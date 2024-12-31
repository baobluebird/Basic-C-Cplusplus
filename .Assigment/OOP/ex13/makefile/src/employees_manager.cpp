#include "employees_manager.h"
#include "employees.h"
#include "experience.h"
#include "fresher.h"
#include "intern.h"

void EmployeeManager::addEmployee(shared_ptr<Employee> document){
    if (!Employee::recycledIds.empty()){
        int recycleId = *Employee::recycledIds.begin();
        Employee::recycledIds.erase(Employee::recycledIds.begin());
        listEmployees.insert(listEmployees.begin() + (recycleId - 1), document);
    }
    else{
        listEmployees.push_back(document);
    }
}

void EmployeeManager::addEmployeeByType(employeeType type) {
    int num;
    cout << "Number of employees to add: ";
    cin >> num;
    
    for (int i = 0; i < num; ++i) {
        shared_ptr<Employee> employee;
        switch (type) {
            case employeeType::Experience:
                employee = make_shared<Experience>();
                break;
            case employeeType::Fresher:
                employee = make_shared<Fresher>();
                break;
            case employeeType::Intern:
                employee = make_shared<Intern>();
                break;
            default:
                cout << "Invalid employee type." << endl;
                return;
        }
        cout << "Enter information for employee " << Employee::employeeTypeToString(type) << " " << i + 1 << ":" << endl;
        employee->inputEmployee();
        addEmployee(employee);
    }
}

void EmployeeManager::editEmployeeById(int id){
    int size = Employee::manageId.size();
    if (id < 1 || id > size){
        cout << "ID not found" << endl;
        return;
    }

    listEmployees[id - 1]->editEmployee();
}

bool EmployeeManager::deleteEmployeeById(int id){
    int size = Employee::manageId.size();
    if (id < 1 || id > size){
        cout << "ID not found" << endl;
        return false;
    }

    listEmployees.erase(listEmployees.begin() + (id - 1));

    cout << "Delete successfully" << endl;
    return true;
}

void settingDisplay(){
    cout << left
         << setw(10) << "ID"
         << setw(20) << "Employee Type"
         << setw(20) << "Full Name"
         << setw(15) << "BirthDay"
         << setw(15) << "Phone"
         << setw(20) << "Email";
}

void EmployeeManager::displayEmployee(){
    settingDisplay();
    cout << left
         << setw(20) << "ExpInYear/GradDate/Majors-"
         << setw(20) << "ProSkill/GradRank/Semester-"
         << setw(30) << "Education/University"
         << endl;
    cout << string(170, '-') << endl;
    size_t size = Employee::manageId.size();
    for (size_t i = 0; i < size; ++i) { 
        shared_ptr<Employee> doc = listEmployees[i];  
        doc->detailEmployee();
    }
    cout << string(170, '-') << endl;
}  

void EmployeeManager::displayExperience(){
    settingDisplay();
    cout << left
         << setw(26) << "ExpInYear"
         << setw(20) << "ProSkill"
         << endl;
    cout << string(170, '-') << endl;
    size_t size = Employee::manageId.size();
    for (size_t i = 0; i < size; ++i){
        shared_ptr<Employee> &doc = listEmployees[i];
        if (doc->getType() == "Experience"){
            doc->detailEmployee();
        }
    }
    cout << string(170, '-') << endl;
}

void EmployeeManager::displayIntern(){
    settingDisplay();
    cout << left
         << setw(26) << "Majors"
         << setw(27) << "Semester"
         << setw(30) << "University Name"
         << endl;
    cout << string(170, '-') << endl;
    size_t size = Employee::manageId.size();
    for (size_t i = 0; i < size; ++i){
        shared_ptr<Employee> &doc = listEmployees[i];
        if (doc->getType() == "Intern"){
            doc->detailEmployee();
        }
    }
    cout << string(170, '-') << endl;
}

void EmployeeManager::displayFresher(){
    settingDisplay();
    cout << left
         << setw(27) << "Graduation Date"
         << setw(26) << "Graduation Rank"
         << setw(30) << "Education"
         << endl;
    cout << string(170, '-') << endl;
    size_t size = Employee::manageId.size();
    for (size_t i = 0; i < size; ++i){
        shared_ptr<Employee> &doc = listEmployees[i];
        if (doc->getType() == "Fresher"){
            doc->detailEmployee();
        }
    }
    cout << string(170, '-') << endl;
}
