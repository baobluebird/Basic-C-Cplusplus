// Một đơn vị sản xuất gồm có các cán bộ là công nhân, kỹ sư, nhân viên. Mỗi cán bộ cần quản lý các dữ liệu: Họ tên, tuổi, giới tính(name, nữ, khác), địa chỉ.

// Cấp công nhân sẽ có thêm các thuộc tính riêng: Bậc (1 đến 10).
// Cấp kỹ sư có thuộc tính riêng: Nghành đào tạo.
// Các nhân viên có thuộc tính riêng: công việc.
// Yêu cầu 1: Xây dựng các lớp CongNhan, KySu, NhanVien kế thừa từ lớp CanBo.

// Yêu cầu 2: Xây dựng lớp QLCB(quản lý cán bộ) cài đặt các phương thức thực hiện các chức năng sau:

// Thêm mới cán bộ.
// Tìm kiếm theo họ tên.
// Hiện thị thông tin về danh sách các cán bộ.
// Thoát khỏi chương trình.

#include<bits/stdc++.h>
//define

#define AddEmployee 1
#define SearchEmployeeByName 2
#define DisplayEmployee 3

using namespace std;
enum class EmployeeType {
    Worker = 1,
    Staff,
    Engineer,
    
};

class Employee {
    protected:
        string name;
        int age;
        string gender;
        string address;
    public:
        Employee() : name(""), age(0), gender(""), address("") {}
        
        Employee(string name, int age, string gender, string address) {
            this->name = name;
            this->age = age;
            this->gender = gender;
            this->address = address;
        }

        virtual void enterInformation() {
            cout << "Enter employee's name: ";
            cin >> name;
            cout << "Enter employee's age: ";
            cin >> age;
            cout << "Enter employee's gender: ";
            cin >> gender;
            cout << "Enter employee's address: ";
            cin >> address;
        }

        string getName() { return name; }

        virtual void displayInformation() {
            cout << "Name: " << this->name << endl;
            cout << "Age: " << this->age << endl;
            cout << "Gender: " << this->gender << endl;
            cout << "Address: " << this->address << endl;
        }

        virtual ~Employee() {
            cout << "Destructor of Employee: " << this->name << endl;
        }
};

class Worker : public Employee {
    private:
        int level;
    public:
        Worker() : level(0) {}
        Worker(string name, int age, string gender, string address, int level)
        : Employee(name, age, gender, address), level(level) {}

        void enterInformation() {
            Employee::enterInformation();
            cout << "Enter level (1-10): ";
            cin >> level;
        
            while (level < 1 || level > 10) {
                cout << "Level must be between 1 and 10. Please re-enter: ";
                cin >> level;
            }
        }

        void displayInformation() {
            cout << "---------- Worker Information ----------" << endl;
            Employee::displayInformation();
            cout << "Level: " << this->level << endl;
        }
};

class Engineer : public Employee {
    private:
        string major;
    public:
        Engineer() : major("") {}
        Engineer(string name, int age, string gender, string address, string major)
        : Employee(name, age, gender, address), major(major) {}

        void enterInformation() {
            Employee::enterInformation();
            cout << "Enter major: ";
            cin >> major;
        }

        void displayInformation() {
            cout << "-------- Engineer Information --------" << endl;
            Employee::displayInformation();
            cout << "Major: " << this->major << endl;
        }
};

class Staff : public Employee {
    private:
        string job;
    public:
        Staff() : job("") {}
        Staff(string name, int age, string gender, string address, string job)
        : Employee(name, age, gender, address), job(job) {}

        void enterInformation() {
            Employee::enterInformation();
            cout << "Enter job: ";
            cin >> job;
        }

        void displayInformation() {
            cout << "--------- Staff Information ---------" << endl;
            Employee::displayInformation();
            cout << "Job: " << this->job << endl;
        }
};

class EmployeeManager {
    private:
        vector<unique_ptr<Employee>> employeeList;
        
    public:
        void addEmployee(unique_ptr<Employee> employee) {
            employeeList.push_back(move(employee));
        }

        void searchByName(string name) {
            bool found = false;
            for(auto& employee : employeeList) {
                if(employee->getName() == name) {
                    employee->displayInformation();
                    found = true;
                }
            }
            if(!found) {
                cout << "No employee found with the name: " << name << endl;
            }
        }

        void displayAll() {
            for(int i = 0; i < employeeList.size(); ++i) {
                cout << "Employee " << i + 1 << " Information" << endl;
                employeeList[i]->displayInformation();
            }
        }
};

void addWorker(EmployeeManager &manager) {
    int num;
    cout << "Number of workers to add: ";
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cout << "Enter information for worker " << i + 1 << ":" << endl;
        unique_ptr<Employee> employee = make_unique<Worker>();
        employee->enterInformation();
        manager.addEmployee(move(employee));
    }
}

void addStaff(EmployeeManager &manager) {
    int num;
    cout << "Number of staff to add: ";
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cout << "Enter information for staff " << i + 1 << ":" << endl;
        unique_ptr<Employee> employee = make_unique<Staff>();
        employee->enterInformation();
        manager.addEmployee(move(employee));
    }
}

void addEngineer(EmployeeManager &manager) {
    int num;
    cout << "Number of engineers to add: ";
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cout << "Enter information for engineer " << i + 1 << ":" << endl;
        unique_ptr<Employee> employee = make_unique<Engineer>();
        employee->enterInformation();
        manager.addEmployee(move(employee));
    }
}

// Main Function
int main() {
    EmployeeManager manager;
    int choice;

    while(1) {
        cout << "------- Menu -------" << endl;
        cout << "1. Add employee" << endl;
        cout << "2. Search employee by name" << endl;
        cout << "3. Display all employees" << endl;
        cout << "0. Exit program" << endl;
        cin >> choice;

        if(choice == 0) {
            break;
        }

        switch (choice) {
            case AddEmployee: {
                cout << "1. Add Worker" << endl;
                cout << "2. Add Staff" << endl;
                cout << "3. Add Engineer" << endl;
                int typeInput; 
                cin >> typeInput;
                EmployeeType type = static_cast<EmployeeType>(typeInput);
                switch (type) {
                    case EmployeeType::Worker: {
                        addWorker(manager);
                        break;
                    }
                    case EmployeeType::Staff: {
                        addStaff(manager);
                        break;
                    }
                    case EmployeeType::Engineer: {
                        addEngineer(manager);
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case SearchEmployeeByName: {
                string name;
                cout << "Enter employee's name to search: ";
                cin >> name;
                manager.searchByName(name);
                break;
            }
            case DisplayEmployee: {
                cout << "--------- All Employees ---------" << endl;
                manager.displayAll();
                break;
            }
            default:
                break;
        }
    }

    return 0;
}
