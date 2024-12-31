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

        string getType() override;
    
        void detailEmployee() override;

        void inputExperienceInYear(bool);

        void inputProSkill(bool);

        void inputEmployee() override;

        void editEmployee() override;
};

#endif