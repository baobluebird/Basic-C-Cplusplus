#ifndef INTERN_H
#define INTERN_H
#include "employees.h"
class Intern : public Employee{
    private:
        string Majors;
        int Semester;
        string University_name;
        employeeType type;
    public:
        Intern();

        Intern(string , string , int , string , string , int , string );

        void detailEmployee() override;


        void inputEmployee() override;

        string getType();
}; 


#endif