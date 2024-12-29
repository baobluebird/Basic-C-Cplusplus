#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iomanip> 
#include <memory>
using namespace std;

class Person{
    private:
        int idNumber;
        string name;
        int age;
        string job;
        static set<int> listIdNumber;
    public:
        Person(): idNumber(0), name(""), age(0), job(""){}
        
        void inputInfoPerson(){
            int temp;
            cout << "Enter ID Number: ";
            cin >> temp;
            while (listIdNumber.find(temp) != listIdNumber.end()) {
                cout << "This number already exists. Please enter another ID Number: ";
                cin >> temp;
            }
            listIdNumber.insert(temp);
            this->idNumber = temp;
            cout << "Enter Name: ";
            cin >> this->name;
            cout << "Enter age: ";
            cin >> this->age;
            cout << "Enter job: ";
            cin >> this->job;
        }

        void displayInfoPerson(){
            cout << setw(10) << this->idNumber << setw(16) << this->name << setw(10) << this->age << setw(10) << this->job  << endl;
        }
        
        ~Person(){
            cout << "Destructor of Person ID: " << idNumber << endl;
        }

};

set<int> Person::listIdNumber;

class Household{
    private:
        int numMember;
        string address;
        vector<shared_ptr<Person>> listPerson;
    public:
        Household(): numMember(0), address(""){}
        
        void inputInfoHousehold(){
            cout << "Enter Number member: ";
            cin >> this->numMember;
            cout << "Enter Address: ";
            cin >> this->address;
            for(int i = 0; i < this->numMember; ++i){
                cout << "Enter information of person " << i + 1 << ":" << endl;
                shared_ptr<Person> person = make_shared<Person>();
                person->inputInfoPerson();
                listPerson.push_back(person);
            }
        }

        void displayInfoHousehold(){
            cout << "Number Member: " << this->numMember << endl;
            cout << "Address: " << this->address << endl;
            cout << left
                 << setw(10) << "ID Number"
                 << setw(16) << "Name"
                 << setw(10) << "Age"
                 << setw(10) << "Job"
                 << endl;
            cout << string(65, '-') << endl; 
            for(shared_ptr<Person> person : listPerson){
                person->displayInfoPerson();
            } 
            cout << string(65, '-') << endl;      
        }
        
        ~Household(){
            cout << "Destructor of Household have address: " << address << endl;
        }

};

class Neighborhood{
    private:
        vector<unique_ptr<Household>> listHousehold;
    public:
        void addHouseHold(){
            cout << "Enter number household: ";
            int n; cin >> n;
            for(int i = 0; i < n; ++i){
                unique_ptr<Household> household = make_unique<Household>();
                cout << "Enter information of household " << i + 1 <<":" << endl;
                household->inputInfoHousehold();
                listHousehold.push_back(move(household));
            }
        }

        void displayNeighborhood(){
            int size = listHousehold.size();
            for(int i = 0; i < size; ++i){
                cout << "Information of household " << i + 1 << ":" << endl;
                listHousehold[i]->displayInfoHousehold();
            }
        }
};

int main(){
    Neighborhood neighborhood;
    neighborhood.addHouseHold();
    neighborhood.displayNeighborhood();
    return 0;
}