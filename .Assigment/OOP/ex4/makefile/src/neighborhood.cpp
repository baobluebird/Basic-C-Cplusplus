#include "neighborhood.h"

void Neighborhood::addHouseHold(){
    cout << "Enter number household: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        unique_ptr<Household> household = make_unique<Household>();
        cout << "Enter information of household " << i + 1 << ":" << endl;
        household->inputInfoHousehold();
        listHousehold.push_back(move(household));
    }
}

void Neighborhood::displayNeighborhood(){
    int num = listHousehold.size();
    for (int i = 0; i < num; ++i)
    {
        cout << "Information of household " << i + 1 << ":" << endl;
        listHousehold[i]->displayInfoHousehold();
    }
}