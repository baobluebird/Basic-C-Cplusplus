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
        
        void detailEmployee() override;

        void inputEmployee() override;


        string getType();
};


#endif