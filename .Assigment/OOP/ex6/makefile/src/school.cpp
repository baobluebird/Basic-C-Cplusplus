#include "school.h"

void School::addClass(){
    cout << "Enter number class: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        unique_ptr<Class> classes = make_unique<Class>();
        cout << "Enter information of class " << i + 1 << ":" << endl;
        classes->inputInfoClass();
        listClass.push_back(move(classes));
    }
}

void School::displayStudent20Years(){
    bool result = false;
    for (auto &classes : listClass)
    {
        result = classes->displayStudent20Years();
        if (!result)
        {
            cout << "Don't have student's age is 20 years old" << endl;
        }
    }
}

void School::findStudentSameAgeAndAddress(int age, string address){
    int total = 0;
    for (auto &classes : listClass)
    {
        total += classes->numberStudentSameAgeAndAddress(age, address);
    }
    if (!total)
    {
        cout << "There are no students with age " << age << " and address " << address << endl;
    }
    else
    {
        cout << "Total students with age " << age << " and address " << address << " is: " << total << endl;
    }
}

void School::displaySchool(){
    int size = listClass.size();
    for (int i = 0; i < size; ++i)
    {
        cout << "Information of class " << i + 1 << ":" << endl;
        listClass[i]->displayInfoClass();
    }
}
