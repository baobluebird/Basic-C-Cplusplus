#ifndef NEIGHBORHOOD_H
#define NEIGHBORHOOD_H
#include "household.h"

class Neighborhood{
    private:
        vector<Household> listHousehold;
    public:
        void addHouseHold();
        void displayNeighborhood();
    
};

#endif