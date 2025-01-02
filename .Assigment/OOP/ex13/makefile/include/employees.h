#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "certificate.h"
#include "utils_employees.h"

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
        vector<Certificate> certificates;
        set<int> manageIdCer;
    protected:
        bool isValidDate(const string&);

        bool isValidPhone(const string&);

        bool isValidEmail(const string&);

        bool isValidFullName(const string&);

        bool isValidString(const string&);

    public:
        static set<int> manageId;
        static set<int> recycledIds;  
        static string employeeTypeToString(employeeType);

        Employee();

        Employee(string , string , string , string , employeeType);

        void generateUniqueId();

        void inputName(bool);

        void inputBirthday(bool);

        void inputPhone(bool);

        void inputEmail(bool);

        void inputCertificates();

        void displayCertificates();

        void displayBasicInfo();

        virtual void inputEmployee();

        virtual void editEmployee();

        virtual void detailEmployee() = 0;

        virtual string getType() = 0;

        virtual ~Employee();
};

#endif
