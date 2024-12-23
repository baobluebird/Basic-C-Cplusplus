#include <iostream>
#include <vector>
 
using namespace std;
 
class CanBo {
    private:
        string Name;
        unsigned int Age;
        string Gender;
        string Address;
 
    public:
        void setName(string name) { Name = name; }  //setter
        string getName() { return Name; }           //getter
 
        void setAge(unsigned int age) {
            if (age > 18) { Age = age; }
        }  
        unsigned int getAge() { return Age; }          
 
        void setGender(string gender) { Gender = gender; }
        string getGender() { return Gender; }
 
        void setAddress(string address) { Address = address; }
        string getAddress() { return Address; }        
 
        CanBo(string name, unsigned int age, string gender, string address) {
            Name = name;
            Age = age;
            Gender = gender;
            Address = address;
        }
 
        virtual void display() {
            cout << "Name: " << Name << ", Age: " << Age
                << ", Gender: " << Gender << ", Address: " << Address << endl;
        }
 
        virtual ~CanBo() {}
 
};
 
class CongNhan:public CanBo {
    private:
        unsigned int Level;
 
    public:
        CongNhan(string name, unsigned int age, string gender, string address, unsigned int level)
                :CanBo(name, age, gender, address)
            {
                Level = level;
            }
        void display() override {
            CanBo::display();
            cout << "Level: " << Level << endl;
        }
   
};
 
class KySu:public CanBo {
    private:
        string Major;
 
    public:
        KySu(string name, unsigned int age, string gender, string address, string major)
                :CanBo(name, age, gender, address)
            {
                Major = major;
            }
        void display() override {
            CanBo::display();
            cout << "Major: " << Major << endl;
        }
};
 
class NhanVien:public CanBo {
    private:
        string Job;
 
    public:
        NhanVien(string name, unsigned int age, string gender, string address, string job)
                :CanBo(name, age, gender, address)
            {
                Job = job;
            }
        void display() override {
            CanBo::display();
            cout << "Job: " << Job << endl;
        }
};
 
 
class QLCB {
private:
    vector<CanBo*> staffList;
 
public:
    void addCanBo(CanBo* canBo) {
        staffList.push_back(canBo);
    }
 
    void searchByName(const string& name) {
        bool found = false;
        for (CanBo* canBo : staffList) {
            if (canBo->getName() == name) {
                canBo->display();
                found = true;
            }
        }
        if (!found) {
            cout << "No staff found with name: " << name << endl;
        }
    }
 
    void displayAll() {
        for (CanBo* canBo : staffList) {
            canBo->display();
            cout << "-----------------------" << endl;
        }
    }
 
    ~QLCB() {
        for (CanBo* canBo : staffList) {
            delete canBo;
        }
    }
};
 
int main() {
    QLCB manager;
    int choice;
 
    do {
        cout << "\n1. Add new staff\n2. Search by name\n3. Display all staff\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
 
        switch (choice) {
        case 1: {
            cout << "\n1. Worker\n2. Engineer\n3. Employee\nEnter staff type: ";
            int type;
            cin >> type;
 
            string name, gender, address;
            unsigned int age;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter gender: ";
            cin.ignore();
            getline(cin, gender);
            cout << "Enter address: ";
            getline(cin, address);
 
            if (type == 1) {
                unsigned int level;
                cout << "Enter level (1-10): ";
                cin >> level;
                manager.addCanBo(new CongNhan(name, age, gender, address, level));
            } else if (type == 2) {
                string major;
                cout << "Enter major: ";
                cin.ignore();
                getline(cin, major);
                manager.addCanBo(new KySu(name, age, gender, address, major));
            } else if (type == 3) {
                string job;
                cout << "Enter job: ";
                cin.ignore();
                getline(cin, job);
                manager.addCanBo(new NhanVien(name, age, gender, address, job));
            }
            break;
        }
        case 2: {
            cout << "Enter name to search: ";
            string name;
            cin.ignore();
            getline(cin, name);
            manager.searchByName(name);
            break;
        }
        case 3:
            manager.displayAll();
            break;
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);
 
    return 0;
}