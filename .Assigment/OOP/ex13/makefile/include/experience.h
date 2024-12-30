#ifndef EXPERIENCE_H
#define EXPERIENCE_H
#include "employees.h"

class Experience : public Employee{
    private:
        int ExpInYear;
        string ProSkill;
        employeeType type;
    public:
        Experience();
        
        Experience(string , string , string , string ,int , string );
    
        void detailEmployee() override;


        void inputEmployee() override;


        string getType();

};

#endif