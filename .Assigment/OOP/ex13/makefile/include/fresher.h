#ifndef FRESHER_H
#define FRESHER_H
#include "employees.h"
class Fresher : public Employee{
    private:
        string Graduation_date;
        string Graduation_rank;
        string Education;
        employeeType type;
    public: 
        Fresher();
        
        Fresher(string , string , string , string , string , string , string );
        
        string getType() override;

        void detailEmployee() override;

        void inputGraduationDate(bool);

        void inputGraduationRank(bool);

        void inputEducation(bool);

        void inputEmployee() override;

        void editEmployee() override;

};

#endif