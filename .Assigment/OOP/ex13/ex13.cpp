#include <iostream>
#include <vector>
#include <memory>
#include <set>
#include <iomanip> 
#include <regex>
#include <limits>

using namespace std;
#define AddEmployee 1
#define EditEmployee 2
#define DeleteEmployee 3
#define DisplayEmployee 4
#define DisplayExperience 5
#define DisplayFresher 6
#define DisplayIntern 7
#define SearchByType 8

enum class employeeType{
    Experience = 0,
    Fresher = 1,
    Intern  = 2
};

class BirthDayException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid birthday format!";
    }
};

class PhoneException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid phone number!";
    }
};

class EmailException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid email format!";
    }
};

class FullNameException : public exception {
public:
    const char* what() const noexcept override {
        return "Full name cannot be empty!";
    }
};

class MenuException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid menu choice! Please enter a valid number.";
    }
};

class Certificate {
    private:
        int CertificatedID;
        string CertificateName;
        string CertificateRank;
        string CertificatedDate;
    public:
        Certificate() : CertificatedID(0), CertificateName(""), CertificateRank(""), CertificatedDate("") {}

        Certificate(int id, string name, string rank, string date)
            : CertificatedID(id), CertificateName(name), CertificateRank(rank), CertificatedDate(date) {}
        void addCertificate() {
            cout << "Enter Certificate ID: ";
            cin >> this->CertificatedID;
            cin.ignore();
            cout << "Enter Certificate Name: ";
            getline(cin, this->CertificateName);
            cout << "Enter Certificate Rank: ";
            getline(cin, this->CertificateRank);
            cout << "Enter Certificate Date: ";
            getline(cin, this->CertificatedDate); 
        }

        void infoCertificates() {
            cout << "ID: " << this->CertificatedID << ", Name: " << this->CertificateName
                << ", Rank: " << this->CertificateRank << ", Date: " << this->CertificatedDate << endl;
        }
};

class Employee{
    private:
        int ID;
        string fullName;
        string birthDay;
        string phone;
        string email;
        employeeType type;
        static int employeeCount;
        vector<shared_ptr<Certificate>> certificates;

    public:
        static set<int> manageId;
        static set<int> recycledIds;  

        Employee() : fullName(""), birthDay(""), phone(""), email("") {
            generateUniqueId();
        }

        Employee(string fullName, string birthDay, int phone, string email,  employeeType type){
            generateUniqueId();
            this->fullName = fullName;
            this->birthDay = birthDay;
            this->phone = phone;
            this->email = email;
            this->type = type;
        }

        void generateUniqueId() {
            if(!recycledIds.empty()){
                this->ID = *recycledIds.begin();
            }else{
                this->ID = employeeCount++;
            }
            manageId.insert(this->ID);
        }

        int getId(){
            return this->ID;
        }

        string getFullName(){
            return this->fullName;
        }

        string getBirthDay(){
            return this->birthDay;
        }

        string getPhone(){
            return this->phone;
        }

        string getEmail(){
            return this->email;
        }

        bool isValidBirthDay(const string& birthday) {
            regex pattern(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\d{4}$)"); 
            if (!regex_match(birthday, pattern)) return false;

            int day, month, year;
            sscanf(birthday.c_str(), "%d/%d/%d", &day, &month, &year);

            int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
                daysInMonth[2] = 29;
            }

            return day <= daysInMonth[month];
        }


        bool isValidPhone(const string& phone) {
            regex pattern(R"(^0\d{9}$)"); 
            return regex_match(phone, pattern);
        }

        bool isValidEmail(const string& email) {
            regex pattern(R"((\w+)(\.|\w)*@(\w+)(\.\w+)+)"); 
            return regex_match(email, pattern);
        }

        bool isValidFullName(const string& fullName) {
            regex pattern(R"(^[A-Za-zÀ-ỹ\s]+$)");
            return regex_match(fullName, pattern) && !fullName.empty();
        }

        static string employeeTypeToString(employeeType type);

        virtual void inputEmployee(){
            while (true) {
                try {
                    cout << "Enter Full Name: ";
                    cin.ignore();
                    getline(cin, this->fullName);
                    if (!isValidFullName(this->fullName)) {
                        throw FullNameException();
                    }
                    break;
                } catch (const FullNameException& e) {
                    cerr << "Error: " << e.what() << endl;
                    cout << "Name must not contain numbers or special characters. Please try again.\n";
                }
            }


            while (true) {
                try {
                    cout << "Enter Birthday (dd/mm/yyyy): ";
                    cin >> this->birthDay;
                    if (!isValidBirthDay(this->birthDay)) {
                        throw BirthDayException();
                    }
                    break;
                } catch (const BirthDayException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }

            while (true) {
                try {
                    cout << "Enter Phone: ";
                    string phoneInput;
                    cin >> phoneInput;
                    if (!isValidPhone(phoneInput)) {
                        throw PhoneException();
                    }
                    this->phone = phoneInput;
                    break;
                } catch (const PhoneException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }

            while (true) {
                try {
                    cout << "Enter Email: ";
                    cin >> this->email;
                    if (!isValidEmail(this->email)) {
                        throw EmailException();
                    }
                    break;
                } catch (const EmailException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }
            int num;
            cout <<"Number of Certificate to add: ";
            cin >> num;
            cin.ignore();
            for(int i = 0; i < num; ++i){
                cout << "Enter information for Certificate " << i + 1 << ":" << endl;
                shared_ptr<Certificate> cer = make_shared<Certificate>();
                cer->addCertificate();
                certificates.push_back(cer);
            }
        }

        void displayCertificates() {
            cout << string(60, '+') << endl;
            cout << "Certificates of " << fullName << ":" << endl;
            for (const auto& cert : certificates) {
                cert->infoCertificates();
            }
            cout << string(60, '+') << endl;
        }

        virtual void editEmployee() {
            int choice;
            while (true) {
                cout << "Select the field to edit:\n";
                cout << "1. Full Name\n";
                cout << "2. Birthday\n";
                cout << "3. Phone\n";
                cout << "4. Email\n";
                cout << "5. Certificates\n";
                cout << "0. Finish Editing\n";
                cout << "Your choice: ";
                cin >> choice;

                cin.ignore();

                switch (choice) {
                    case 1: {
                        while (true) {
                            try {
                                cout << "Enter Full Name: ";
                                getline(cin, this->fullName);
                                if (!isValidFullName(this->fullName)) {
                                    throw FullNameException();
                                }
                                break;
                            } catch (const FullNameException& e) {
                                cerr << "Error: " << e.what() << endl;
                            }
                        }
                        break;
                    }
                    case 2: {
                        while (true) {
                            try {
                                cout << "Enter Birthday (dd/mm/yyyy): ";
                                cin >> this->birthDay;
                                if (!isValidBirthDay(this->birthDay)) {
                                    throw BirthDayException();
                                }
                                break;
                            } catch (const BirthDayException& e) {
                                cerr << "Error: " << e.what() << endl;
                            }
                        }
                        break;
                    }
                    case 3: {
                        while (true) {
                            try {
                                cout << "Enter Phone: ";
                                string phoneInput;
                                cin >> phoneInput;
                                if (!isValidPhone(phoneInput)) {
                                    throw PhoneException();
                                }
                                this->phone = phoneInput;
                                break;
                            } catch (const PhoneException& e) {
                                cerr << "Error: " << e.what() << endl;
                            }
                        }
                        break;
                    }
                    case 4: {
                        while (true) {
                            try {
                                cout << "Enter Email: ";
                                cin >> this->email;
                                if (!isValidEmail(this->email)) {
                                    throw EmailException();
                                }
                                break;
                            } catch (const EmailException& e) {
                                cerr << "Error: " << e.what() << endl;
                            }
                        }
                        break;
                    }
                    case 5: {
                        cout << "Updating certificates...\n";
                        certificates.clear();
                        int num;
                        cout << "Number of Certificates to add: ";
                        cin >> num;
                        cin.ignore();
                        for (int i = 0; i < num; ++i) {
                            cout << "Enter information for Certificate " << i + 1 << ":" << endl;
                            unique_ptr<Certificate> cer = make_unique<Certificate>();
                            cer->addCertificate();
                            certificates.push_back(move(cer));
                        }
                        break;
                    }
                    case 0:
                        cout << "Finished editing.\n";
                        return;
                    default:
                        cout << "Invalid choice! Please select again.\n";
                }
            }
        }


        virtual void detailEmployee() = 0;

        virtual string getType() = 0;

        virtual ~Employee(){
            manageId.erase(this->ID);
            recycledIds.insert(this->ID);
            cout << "Destructor of ID: " << this->ID << endl;
        }
};

set<int> Employee::manageId;
set<int> Employee::recycledIds;
int Employee::employeeCount = 1;

string Employee::employeeTypeToString(employeeType type) {
    switch (type) {
        case employeeType::Experience: return "Experience";
        case employeeType::Fresher: return "Fresher";
        case employeeType::Intern: return "Intern";
        default: return "Unknown";
    }
}

class Experience : public Employee{
    private:
        int ExpInYear;
        string ProSkill;
        employeeType type;
    public:
        Experience() : ExpInYear(0), ProSkill("") {
            type = employeeType::Experience;
        }
        
        Experience(string fullName, string birthDay, int phone, string email,int ExpInYear, string ProSkill)
        : Employee(fullName, birthDay, phone, email, employeeType::Experience), ExpInYear(ExpInYear), ProSkill(ProSkill) {
            this->type = employeeType::Experience;
        }
    
        void detailEmployee() override {
            cout << left
                << setw(10) << getId()
                << setw(20) << Employee::employeeTypeToString(this->type)
                << setw(20) << getFullName()
                << setw(15) << getBirthDay()
                << setw(15) << getPhone()
                << setw(20) << getEmail()
                << setw(20) << ExpInYear
                << setw(20) << ProSkill
                << endl;
            displayCertificates();
        }


        void inputEmployee() override{
            Employee::inputEmployee();
            cout << "Enter Experience In Year: ";
            cin >> this->ExpInYear;
            cin.ignore();
            cout << "Enter Pro Skill: ";
            cin >> this->ProSkill;
        }


        string getType(){
            return Employee::employeeTypeToString(type);
        }

};

class Fresher : public Employee{
    private:
        string Graduation_date;
        string Graduation_rank;
        string Education;
        employeeType type;
    public: 
        Fresher() : Graduation_date(""), Graduation_rank(""), Education(""){
            type = employeeType::Fresher;
        }
        
        Fresher(string fullName, string birthDay, int phone, string email, string Graduation_date, string Graduation_rank, string Education)
        : Employee(fullName, birthDay, phone, email, employeeType::Fresher), Graduation_date(Graduation_date), Graduation_rank(Graduation_rank), Education(Education) {
            this->type = employeeType::Fresher;
        }
        
        void detailEmployee() override {
            cout << left
                << setw(10) << getId()                               
                << setw(20) << Employee::employeeTypeToString(this->type)
                << setw(20) << getFullName() 
                << setw(15) << getBirthDay()                       
                << setw(15) << getPhone()                        
                << setw(20) << getEmail()                          
                << setw(20) << Graduation_date                        
                << setw(20) << Graduation_rank                        
                << setw(30) << Education                               
                << endl;
            displayCertificates();
        }


        void inputEmployee() override{
            Employee::inputEmployee();
            cout << "Enter Graduation Date: ";
            cin >> this->Graduation_date;
            cout << "Enter Graduation Rank: ";
            cin >> this->Graduation_rank;
            cout << "Enter Education: ";
            cin >> this->Education;
        }


        string getType(){
            return Employee::employeeTypeToString(type);
        }
};

class Intern : public Employee{
    private:
        string Majors;
        int Semester;
        string University_name;
        employeeType type;
    public:
        Intern() : Majors(""), Semester(0), University_name(""){
            type = employeeType::Intern;
        }

        Intern(string fullName, string birthDay, int phone, string email, string Majors, int Semester, string University_name)
        : Employee(fullName, birthDay, phone, email, employeeType::Intern), Majors(Majors), Semester(Semester), University_name(University_name) {
            this->type = employeeType::Intern;
        }

        void detailEmployee() override {
            cout << left
                << setw(10) << getId()
                << setw(20) << Employee::employeeTypeToString(this->type)
                << setw(20) << getFullName()
                << setw(15) << getBirthDay()
                << setw(15) << getPhone()
                << setw(20) << getEmail()
                << setw(20) << Majors
                << setw(20) << Semester
                << setw(30) << University_name
                << endl;
            displayCertificates();
        }


        void inputEmployee() override{
            Employee::inputEmployee();
            cout << "Enter Majors: ";
            cin >> this->Majors;
            cout << "Enter Semester: ";
            cin >> this->Semester;
            cout << "Enter University Name: ";
            cin >> this->University_name;
        }

        string getType(){
            return Employee::employeeTypeToString(type);
        }
}; 

class EmployeeManager{
    private:
        vector<shared_ptr<Employee>> listEmployees;
    public:
        void addEmployee(shared_ptr<Employee> document) {
            if (!Employee::recycledIds.empty()) {
                int recycleId = *Employee::recycledIds.begin();
                Employee::recycledIds.erase(Employee::recycledIds.begin());
                listEmployees.insert(listEmployees.begin() + (recycleId - 1), document);
            } else {
                listEmployees.push_back(document);  
            }
        }

        void editEmployeeById(int id) {
            int size = Employee::manageId.size();
            if (id < 1 || id > size) {
                cout << "ID not found" << endl;
                return;
            }

            listEmployees[id - 1]->editEmployee();
        }

        bool deleteEmployeeById(int id) {
            int size = Employee::manageId.size();
            if (id < 1 || id > size) {
                cout << "ID not found" << endl;
                return false;
            }

            listEmployees.erase(listEmployees.begin() + (id - 1));

            cout << "Delete successfully" << endl;
            return true;
        }

        void displayEmployee(){
            cout << left
                 << setw(10) << "ID"
                 << setw(20) << "Employee Type"
                 << setw(20) << "Full Name"
                 << setw(15) << "BirthDay"
                 << setw(15) << "Phone"
                 << setw(20) << "Email"
                 << setw(20) << "ExpInYear/GradDate/Majors"
                 << setw(20) << "ProSkill/GradRank/Semester"
                 << setw(30) << "Education/University"
                 << endl;
            cout << string(170, '-') << endl;
            for (size_t i = 0; i < listEmployees.size(); ++i) { 
                shared_ptr<Employee> doc = listEmployees[i];  
                doc->detailEmployee();
            }
            cout << string(170, '-') << endl;
        }

        void displayIntern(){
            cout << left
                 << setw(10) << "ID"
                 << setw(20) << "Employee Type"
                 << setw(20) << "Full Name"
                 << setw(15) << "BirthDay"
                 << setw(15) << "Phone"
                 << setw(20) << "Email"
                 << setw(20) << "Majors"
                 << setw(20) << "Semester"
                 << setw(30) << "University Name"
                 << endl;
            cout << string(170, '-') << endl;
            for (size_t i = 0; i < listEmployees.size(); ++i) { 
                shared_ptr<Employee> doc = listEmployees[i];  
                if (doc->getType() == "Intern") {
                    doc->detailEmployee();
                }
            }
            cout << string(170, '-') << endl;
        }

        void displayExperience(){
            cout << left
                 << setw(10) << "ID"
                 << setw(20) << "Employee Type"
                 << setw(20) << "Full Name"
                 << setw(15) << "BirthDay"
                 << setw(15) << "Phone"
                 << setw(20) << "Email"
                 << setw(20) << "ExpInYear"
                 << setw(20) << "ProSkill"
                 << endl;
            cout << string(170, '-') << endl;
            for (size_t i = 0; i < listEmployees.size(); ++i) { 
                shared_ptr<Employee> doc = listEmployees[i];  
                if (doc->getType() == "Experience") {
                    doc->detailEmployee();
                }
            }
            cout << string(170, '-') << endl;
        }

        void displayFresher(){
            cout << left
                 << setw(10) << "ID"
                 << setw(20) << "Employee Type"
                 << setw(20) << "Full Name"
                 << setw(15) << "BirthDay"
                 << setw(15) << "Phone"
                 << setw(20) << "Email"
                 << setw(20) << "Graduation Date"
                 << setw(20) << "Graduation Rank"
                 << setw(30) << "Education"
                 << endl;
            cout << string(170, '-') << endl;
            for (size_t i = 0; i < listEmployees.size(); ++i) { 
                shared_ptr<Employee> doc = listEmployees[i];  
                if (doc->getType() == "Fresher") {
                    doc->detailEmployee();
                }
            }
            cout << string(170, '-') << endl;
        }

        void searchEmployeeByType(string type) {
            bool found = false;
            for (size_t i = 0; i < listEmployees.size(); ++i) { 
                shared_ptr<Employee> doc = listEmployees[i];   
                if (doc->getType() == type) {
                    doc->detailEmployee();
                    found = true;
                }
            }
            if (!found) {
                cout << "No employee of type " << type << " found." << endl;
            }
        }
};

void addExperience(EmployeeManager& manager){
    int num;
    cout << "Number of Experience to add: ";
    cin >> num;
    cin.ignore();
    for(int i = 0; i < num; ++i){
        cout << "Enter information for experience " << i + 1 << ":" << endl;
        shared_ptr<Employee> employee = make_shared<Experience>();
        employee->inputEmployee();
        manager.addEmployee(move(employee));
    }
}

void addFresher(EmployeeManager& manager){
    int num;
    cout << "Number of Fresher to add: ";
    cin >> num;
    cin.ignore();
    for(int i = 0; i < num; ++i){
        cout << "Enter information for fresher " << i + 1 << ":" << endl;
        shared_ptr<Employee> employee = make_shared<Fresher>();
        employee->inputEmployee();
        manager.addEmployee(move(employee));
    }
}

void addIntern(EmployeeManager& manager){
    int num;
    cout << "Number of Intern to add: ";
    cin >> num;
    cin.ignore();
    for(int i = 0; i < num; ++i){
        cout << "Enter information for intern " << i + 1 << ":" << endl;
        shared_ptr<Employee> employee = make_shared<Intern>();
        employee->inputEmployee();
        manager.addEmployee(move(employee));
    }
}



int main() {
    EmployeeManager manager;
    int choice;

    while (1) {
        try {
            cout << "------- Menu -------" << endl;
            cout << "1. Add Employee" << endl;
            cout << "2. Edit employee by id" << endl;
            cout << "3. Delete employee by id" << endl;
            cout << "4. Display all employee" << endl;
            cout << "5. Display all experience" << endl;
            cout << "6. Display all fresher" << endl;
            cout << "7. Display all intern" << endl;
            cout << "8. Search employee by type" << endl;
            cout << "0. Exit program" << endl;
            cout << "Your choice: ";
            
            cin >> choice;

            if (cin.fail()) {  
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                throw MenuException();
            }

            if (choice < 0 || choice > 8) {
                throw MenuException();
            }

            if (choice == 0) {
                cout << "Exiting program..." << endl;
                break;
            }

            switch (choice) {
                case AddEmployee: {
                    try {
                        cout << "0. Add Experience" << endl;
                        cout << "1. Add Fresher" << endl;
                        cout << "2. Add Intern" << endl;
                        int typeInput;
                        cin >> typeInput;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            throw MenuException();
                        }

                        employeeType type = static_cast<employeeType>(typeInput);
                        switch (type) {
                            case employeeType::Experience: {
                                addExperience(manager);
                                break;
                            }
                            case employeeType::Fresher: {
                                addFresher(manager);
                                break;
                            }
                            case employeeType::Intern: {
                                addIntern(manager);
                                break;
                            }
                            default:
                                cout << "Invalid choice" << endl;
                                break;
                        }
                        break;
                    } catch (const exception& e) {
                        cerr << "Exception: " << e.what() << endl;
                    }
                    break;
                }
                case EditEmployee: {
                    int id;
                    cout << "Enter employee's id to edit: ";
                    cin >> id;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw MenuException();
                    }

                    manager.editEmployeeById(id);
                    break;
                }
                case DeleteEmployee: {
                    int id;
                    cout << "Enter employee's id to delete: ";
                    cin >> id;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw MenuException();
                    }

                    manager.deleteEmployeeById(id);
                    break;
                }
                case DisplayEmployee: {
                    cout << "--------- All Employees ---------" << endl;
                    manager.displayEmployee();
                    break;
                }
                case DisplayExperience: {
                    cout << "--------- All Experience ---------" << endl;
                    manager.displayExperience();
                    break;
                }
                case DisplayFresher: {
                    cout << "--------- All Fresher ---------" << endl;
                    manager.displayFresher();
                    break;
                }
                case DisplayIntern: {
                    cout << "--------- All Intern ---------" << endl;
                    manager.displayIntern();
                    break;
                }
                case SearchByType: {
                    string type;
                    cout << "Enter employee's type to search: ";
                    cin >> type;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw MenuException();
                    }

                    manager.searchEmployeeByType(type);
                    break;
                }
                default:
                    cout << "Invalid choice" << endl;
                    break;
            }
        } catch (const MenuException& e) {
            cerr << "Error: " << e.what() << endl;
        } catch (const exception& e) {
            cerr << "Unexpected Error: " << e.what() << endl;
        }
    }

    return 0;
}
