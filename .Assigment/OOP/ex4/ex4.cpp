// Để quản lý các hộ dân cư trong một khu phố, người ta cần các thông tin sau: Số thành viên trong gia đình, Số nhà, thông tin mỗi cá nhân trong gia đình. Với mỗi cá nhân, người ta quản lý các thông tin sau: Họ tên, Tuổi, Nghề nghiệp, số chứng minh nhân dân(duy nhất cho mỗi người).

// Yêu cầu 1: Hãy xây dựng lớp Nguoi để quản lý thông tin của mỗi cá nhân.

// Yêu cầu 2: Xây dựng lớp HoGiaDinh để quản lý thông tin của từng hộ gia đình.

// Yêu cầu 2: Xây dựng lớp KhuPho để quản lý các thông tin của từng hộ gia đình.

// Yêu cầu 3: Nhập n hộ dân. (n nhập từ bàn phím), hiển thị thông tin của các hộ trong khu phố.

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
        vector<Person> listPerson;
    public:
        Household(): numMember(0), address(""){}
        
        void inputInfoHousehold(){
            cout << "Enter Number member: ";
            cin >> this->numMember;
            cout << "Enter Address: ";
            cin >> this->address;
            for(int i = 0; i < this->numMember; ++i){
                cout << "Enter information of person " << i + 1 << ":" << endl;
                Person person;
                person.inputInfoPerson();
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
            for(Person person : listPerson){
                person.displayInfoPerson();
            } 
            cout << string(65, '-') << endl;      
        }
        
        ~Household(){
            cout << "Destructor of Household have address: " << address << endl;
        }

};

class Neighborhood{
    private:
        vector<Household> listHousehold;
    public:
        void addHouseHold(){
            cout << "Enter number household: ";
            int n; cin >> n;
            for(int i = 0; i < n; ++i){
                Household household;
                cout << "Enter information of household " << i + 1 <<":" << endl;
                household.inputInfoHousehold();
                listHousehold.push_back(household);
            }
        }

        void displayNeighborhood(){
            int size = listHousehold.size();
            for(int i = 0; i < size; ++i){
                cout << "Information of household " << i + 1 << ":" << endl;
                listHousehold[i].displayInfoHousehold();
            }
        }
};

int main(){
    Neighborhood neighborhood;
    neighborhood.addHouseHold();
    neighborhood.displayNeighborhood();
    return 0;
}