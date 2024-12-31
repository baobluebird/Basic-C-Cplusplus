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

        Intern(string , string , string , string , string , int , string );

        string getType() override;

        void detailEmployee() override;

        void inputMajors(bool);

        void inputSemester(bool);

        void inputUniversityName(bool);

        void inputEmployee() override;

        void editEmployee() override;

}; 


#endif