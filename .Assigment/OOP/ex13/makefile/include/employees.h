#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "certificate.h"

#include <vector>
#include <memory>
#include <set>
#include <iomanip> 
#include <regex>
#include <limits>

enum class employeeType{
    Experience = 0,
    Fresher = 1,
    Intern  = 2
};

class Employee{
    private:
        int ID;
        string fullName;
        string birthDay;
        string phone;
        string email;
        employeeType type;
        static int employeeCount;
        vector<unique_ptr<Certificate>> certificates;

    public:
        static set<int> manageId;
        static set<int> recycledIds;  

        Employee();

        Employee(string , string , string , string ,  employeeType );
        void generateUniqueId();

        int getId();

        string getFullName();

        string getBirthDay();

        string getPhone();

        string getEmail();

        bool isValidBirthDay(const string&);

        bool isValidPhone(const string&);

        bool isValidEmail(const string&);

        bool isValidFullName(const string&);

        static string employeeTypeToString(employeeType type);

        void displayCertificates();

        virtual void inputEmployee();

        virtual void editEmployee();

        virtual void detailEmployee() = 0;

        virtual string getType() = 0;

        virtual ~Employee();
};

#endif
