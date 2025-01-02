#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iomanip> 
#include <memory>

#define AddStudent 1
#define DisplayStudent20Years 2
#define FindStudentSameAgeAndAddress 3


using namespace std;

class Student{
    private:
        string name;
        int age;
        string address;
    public:
        Student(): name(""), age(0), address(""){}
        
        int getAge(){
            return this->age;
        }

        string getAddress(){
            return this->address;
        }

        void inputInfoStudent(){
            cout << "Enter Name: ";
            cin >>this->name;
            cout << "Enter age: ";
            cin >> this->age;
            cout << "Enter address: ";
            cin >> this->address;
        }
        
        void displayInfoStudent(){
            cout << setw(16) << this->name << setw(10) << this->age << setw(10) << this->address  << endl;
        }
        
        ~Student(){}

};


class Class{
    private:
        string nameClass;
        vector<shared_ptr<Student>> listStudents;
    public:
        Class(): nameClass(""){}
        
        void inputInfoClass(){
            int numberStudent;
            cout << "Enter Number Student: ";
            cin >> numberStudent;
            cout << "Enter Name Class: ";
            cin >> this->nameClass;
            for(int i = 0; i < numberStudent; ++i){
                cout << "Enter information of person " << i + 1 << ":" << endl;
                shared_ptr<Student> student = make_shared<Student>();
                student->inputInfoStudent();
                listStudents.push_back(student);
            }
        }

        void displayInfoClass(){
            cout << "Name Class: " << this->nameClass << endl;
            cout << left
                 << setw(16) << "Name"
                 << setw(10) << "Age"
                 << setw(10) << "Address"
                 << endl;
            cout << string(65, '-') << endl; 
            for(shared_ptr<Student> person : listStudents){
                person->displayInfoStudent();
            } 
            cout << string(65, '-') << endl;      
        }

        bool displayStudent20Years(){
            bool found = false;
            cout << string(65, '-') << endl; 
            cout << "Name Class: " << this->nameClass << endl;
            cout << left
                 << setw(16) << "Name"
                 << setw(10) << "Age"
                 << setw(10) << "Address"
                 << endl;
            for(shared_ptr<Student> student : listStudents){
                if(student->getAge() == 20){
                    student->displayInfoStudent();
                    found = true;
                }
            }
            cout << string(65, '-') << endl; 
            return found;
        }

        int numberStudentSameAgeAndAddress(int age, string address){
            int num = 0;
            
            for(shared_ptr<Student> student : listStudents){
                if(student->getAge() == age && student->getAddress() == address){
                    num++;
                }
            }
            return num;
        }
        
        ~Class(){
            cout << "Destructor of Household have address: " << nameClass << endl;
        }

};

class School{
    private:
        vector<Class> listClass;
    public:
        void addClass(){
            cout << "Enter number class: ";
            int n; cin >> n;
            for(int i = 0; i < n; ++i){
                Class classes;
                cout << "Enter information of class " << i + 1 <<":" << endl;
                classes.inputInfoClass();
                listClass.push_back(classes);
            }
        }

        void displayStudent20Years(){
            bool result = false;
            for(Class classes : listClass){
                result = classes.displayStudent20Years();
                if(!result){
                    cout << "Don't have student's age is 20 years old" << endl;
                }
            }
            
        }

        void findStudentSameAgeAndAddress(int age, string address){
            int total  = 0;
            for(Class classes : listClass){
                total += classes.numberStudentSameAgeAndAddress(age, address);
            }
            if(!total){
                cout << "There are no students with age " << age << " and address " << address << endl;
            }else{
                cout << "Total students with age " << age << " and address " << address << " is: " << total << endl;
            }
        }

        void displaySchool(){
            int size = listClass.size();
            for(int i = 0; i < size; ++i){
                cout << "Information of class " << i + 1 << ":" << endl;
                listClass[i].displayInfoClass();
            }
        }
};

int main() {
    School school;
    int choice;

    while(1) {
        cout << "------- Menu -------" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display all student under 20 years old" << endl;
        cout << "3. Number student have same age and address" << endl;
        cout << "0. Exit program" << endl;
        cin >> choice;

        if(choice == 0) {
            break;
        }

        switch (choice) {
            case AddStudent: {
                cout << "--------- Add Student ---------" << endl;
                school.addClass();
                break;
            }
            case DisplayStudent20Years: {
                cout << "--------- All Student Under 20 Years Old ---------" << endl;
                school.displayStudent20Years();
                break;
            }
            case FindStudentSameAgeAndAddress: {
                int age; string address;
                cout << "Enter school's age to find: ";
                cin >> age;
                cout << "Enter school's address to find: ";
                cin >> address;
                school.findStudentSameAgeAndAddress(age, address);
                break;
            }
            default:
                break;
        }
    }

    return 0;
}
