#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H
#include "person.h"

class Household{
    private:
        int numMember;
        string address;
        vector<Person> listPersons;
    public:
        Household();
        void inputInfoHousehold();
        void displayInfoHousehold();
        ~Household();
};

#endif