#include <iostream>
#include <vector>
#include <memory>
#include <set>
#include <iomanip> 
#include <regex>
#include <limits>

using namespace std;
//define menu
#define AddEmployee 1
#define EditEmployee 2
#define DeleteEmployee 3
#define DisplayEmployee 4
#define DisplayExperience 5
#define DisplayFresher 6
#define DisplayIntern 7
#define Exit 0
//define editEmployee
#define EditName 1
#define EditBirthDay 2
#define EditPhone 3
#define EditEmail 4
#define EditCertificates 5
#define FinishEdit 0
//define editEmployee Experience
#define EditExpInYear 6
#define EditProSkill 7
//define editEmployee Fresher
#define EditGraduationDate 6
#define EditGraduationRank 7
#define EditEducation 8
//define editEmployee Intern
#define EditMajors 6
#define EditSemester 7
#define EditUniversityName 8
//define editEmployee Certificate
#define EditCerID 1
#define EditCerName 2
#define EditCerRank 3
#define EditCerDate 4


enum class employeeType{
    Experience = 0,
    Fresher = 1,
    Intern  = 2
};

class DateException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid date format!";
    }
};

class PhoneException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid phone number! Must be starts with 0 and contains no characters";
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
        return "Invalid name. Name must not contain numbers or special characters (Minimum 3 characters)!";
    }
};

class MenuException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid menu choice! Please enter a valid number of 0 -> 8.";
    }
};

class MenuAddEmployeeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid menu choice! Please enter a valid number of 0 -> 2.";
    }
};

class MustBeNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid menu choice! Please enter a valid number.";
    }
};

class MustBeStringException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid input! Please enter a valid string (no numbers or empty input).";
    }
};

class Certificate {
    private:
        int CertificatedID;
        string CertificateName;
        string CertificateRank;
        string CertificatedDate;
    protected:
        bool isValidString(const string& str) {
            return !str.empty() && regex_match(str, regex("^(?=.*[A-Za-zÀ-ỹ])[A-Za-zÀ-ỹ0-9\\s]+$"));
        }

        bool isValidDate(const string& birthday) {
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

    public:
        Certificate() : CertificatedID(0), CertificateName(""), CertificateRank(""), CertificatedDate("") {}

        Certificate(int id, string name, string rank, string date)
            : CertificatedID(id), CertificateName(name), CertificateRank(rank), CertificatedDate(date) {}

        int getId(){
            return this->CertificatedID;
        }

        void setId(int id){
            this->CertificatedID = id;
        }

        void setName(string name){
            this->CertificateName = name;
        }

        void setRank(string rank){
            this->CertificateRank = rank;
        }

        void setDate(string date){
            this->CertificatedDate = date;
        }

        void addCertificate(int id) {
            this->CertificatedID = id;
            cin.ignore();

            while (true) {
                try {
                    cout << "Enter Certificate Name: ";
                    getline(cin, this->CertificateName);
                    
                    if (!isValidString(this->CertificateName)) {
                        throw MustBeStringException();
                    }
                    break; 
                }
                catch (const MustBeStringException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }

            while (true) {
                try {
                    cout << "Enter Certificate Rank: ";
                    getline(cin, this->CertificateRank);
                    
                    if (!isValidString(this->CertificateRank)) {
                        throw MustBeStringException();
                    }
                    break;
                }
                catch (const MustBeStringException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }

            while (true) {
                try {
                    cout << "Enter Certificate Date: ";
                    getline(cin, this->CertificatedDate);
                    
                    if (!isValidDate(this->CertificatedDate)) {
                        throw DateException();
                    }
                    break;
                }
                catch (const DateException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }
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
        vector<unique_ptr<Certificate>> certificates;
        set<int> manageIdCer;
    protected:
        bool isValidDate(const string& birthday) {
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
            regex pattern(R"(^[A-Za-zÀ-ỹ ]{3,}$)");
            return regex_match(fullName, pattern);
        }

        bool isValidString(const string& str) {
            return !str.empty() && regex_match(str, regex("^[A-Za-zÀ-ỹ\\s]+$"));
        }

    public:
        static set<int> manageId;
        static set<int> recycledIds;  
        static string employeeTypeToString(employeeType type);

        Employee() : fullName(""), birthDay(""), phone(""), email("") {
            generateUniqueId();
        }

        Employee(string fullName, string birthDay, string phone, string email,  employeeType type){
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

        void inputName(bool isInput){
            while (true) {
                try {
                    isInput == true ? cout << "Enter Full Name: " : cout << "Enter new Full Name: ";
                    cin.ignore();
                    getline(cin, this->fullName);
                    if (!isValidFullName(this->fullName)) {
                        throw FullNameException();
                    }
                    break;
                } catch (const FullNameException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }
        }

        void inputBirthday(bool isInput){
            while (true) {
                try {
                    isInput == true ? cout << "Enter Birthday (dd/mm/yyyy): " : cout << "Enter new Birthday (dd/mm/yyyy): ";
                    cin >> this->birthDay;
                    if (!isValidDate(this->birthDay)) {
                        throw DateException();
                    }
                    break;
                } catch (const DateException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }
        }

        void inputPhone(bool isInput){
            while (true) {
                try {
                    isInput == true ? cout << "Enter Phone: " : cout << "Enter new Phone: ";
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
        }

        void inputEmail(bool isInput){
            while (true) {
                try {
                    isInput == true ? cout << "Enter Email: " : cout << "Enter new Email: ";
                    cin >> this->email;
                    if (!isValidEmail(this->email)) {
                        throw EmailException();
                    }
                    break;
                } catch (const EmailException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }
        }   

        void inputCertificates(){
            int num;
            while (true) {
                try {
                    cout << "Number of Certificates to add: ";
                    cin >> num;

                    if (cin.fail() || num < 0) { 
                        cin.clear();  
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                        throw MustBeNumberException();
                    }

                    if (num == 0) {
                        cout << "No certificates to add." << endl;
                        return;  
                    }

                    break; 
                }
                catch (const MustBeNumberException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }

            cin.ignore();
            for (int i = 0; i < num; ++i) {
                cout << "Enter information for Certificate " << i + 1 << ":" << endl;
                
                int idCer;
                while (true) {
                    try {
                        cout << "Enter Certificate ID: ";
                        cin >> idCer;

                        if (cin.fail() || idCer < 1) { 
                            cin.clear();  
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                            throw MustBeNumberException();
                        }

                        if (manageIdCer.find(idCer) != manageIdCer.end()) {
                            cout << "Certificate ID already exists. Please enter a different ID." << endl;
                            continue;
                        }

                        break; 
                    }
                    catch (const MustBeNumberException& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                }

                unique_ptr<Certificate> cer = make_unique<Certificate>();
                cer->addCertificate(idCer);
                manageIdCer.insert(cer->getId());
                certificates.push_back(move(cer));
            }
        }

        void displayCertificates() {
            cout << string(60, '*') << endl;
            cout << "Certificates of " << fullName << ":" << endl;
            if(certificates.empty()){
                cout << "No certificates found." << endl;
            }else{
                for (const auto& cert : certificates) {
                    cert->infoCertificates();
                }
            }
            cout << string(60, '*') << endl;
        }

        void displayBasicInfo() {
            cout << left
                << setw(10) << this->ID
                << setw(20) << Employee::employeeTypeToString(this->type)
                << setw(20) << this->fullName
                << setw(15) << this->birthDay
                << setw(15) << this->phone
                << setw(20) << this->email;
        }

        virtual void inputEmployee(){
            
            inputName(true);

            inputBirthday(true);

            inputPhone(true);

            inputEmail(true);

            inputCertificates();
            
        }

        virtual void editEmployee() {
            int choice;
            while (true) {
                detailEmployee();
                cout << "Select the field to edit:\n";
                cout << "1. Full Name\n";
                cout << "2. Birthday\n";
                cout << "3. Phone\n";
                cout << "4. Email\n";
                cout << "5. Certificates\n";
                cout << "0. Next Editing\n";
                cout << "Your choice: ";
                cin >> choice;

                cin.ignore();

                switch (choice) {
                    case EditName: {
                        inputName(false);
                        break;
                    }
                    case EditBirthDay: {
                        inputBirthday(false);
                        break;
                    }
                    case EditPhone: {
                        inputPhone(false);
                        break;
                    }
                    case EditEmail: {
                        inputEmail(false);
                        break;
                    }
                    case EditCertificates: {
                        if (certificates.empty()) {
                            cout << "No certificates found for this employee.\n";
                            break;
                        }

                        cout << "---- Current Certificates ----\n";
                        for (size_t i = 0; i < certificates.size(); ++i) {
                            cout << i + 1 << ". ";
                            certificates[i]->infoCertificates();
                        }

                        int selectedId;
                        cout << "Enter Certificate ID to edit (or 0 to cancel): ";
                        cin >> selectedId;

                        if (selectedId == 0) {
                            cout << "Canceled editing certificates.\n";
                            break;
                        }

                        bool found = false;
                        for (size_t i = 0; i < certificates.size(); ++i) {
                            if (certificates[i]->getId() == selectedId) {
                                found = true;
                                cout << "Editing Certificate ID: " << selectedId << "\n";

                                int subChoice;
                                while (true) {
                                    certificates[i]->infoCertificates();
                                    cout << "\nSelect the attribute to edit:\n";
                                    cout << "1. Certificate ID\n";
                                    cout << "2. Certificate Name\n";
                                    cout << "3. Certificate Rank\n";
                                    cout << "4. Certificate Date\n";
                                    cout << "0. Finish Editing\n";
                                    cout << "Your choice: ";
                                    cin >> subChoice;
                                    cin.ignore();

                                    switch (subChoice) {
                                        case EditCerID: {  
                                            int newId;
                                            while (true) {
                                                try {
                                                    cout << "Enter new Certificate ID: ";
                                                    cin >> newId;

                                                    if (cin.fail() || newId < 1) {
                                                        cin.clear();
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        throw MustBeNumberException();
                                                    }

                                                    if (manageIdCer.find(newId) != manageIdCer.end() && newId != selectedId) {
                                                        cout << "Certificate ID already exists. Try again.\n";
                                                        continue;
                                                    }

                                                    manageIdCer.erase(certificates[i]->getId());
                                                    certificates[i]->setId(newId);
                                                    manageIdCer.insert(newId);
                                                    break;
                                                }
                                                catch (const MustBeNumberException& e) {
                                                    cerr << "Error: " << e.what() << endl;
                                                }
                                            }
                                            break;
                                        }
                                        case EditCerName: {
                                            string newName;  
                                            while (true) {
                                                try {
                                                    cout << "Enter new Certificate Name: ";
                                                    getline(cin, newName);

                                                    if (!isValidString(newName)) {
                                                        throw MustBeStringException();
                                                    }
                                                    certificates[i]->setName(newName);
                                                    break;
                                                }
                                                catch (const MustBeStringException& e) {
                                                    cerr << "Error: " << e.what() << endl;
                                                }
                                            }
                                            break;
                                        }
                                        case EditCerRank: {
                                            string newRank;
                                            while (true) {
                                                try {
                                                    cout << "Enter new Certificate Rank: ";
                                                    getline(cin, newRank);

                                                    if (!isValidString(newRank)) {
                                                        throw MustBeStringException();
                                                    }
                                                    certificates[i]->setRank(newRank);
                                                    break;
                                                }
                                                catch (const MustBeStringException& e) {
                                                    cerr << "Error: " << e.what() << endl;
                                                }
                                            }
                                            break;
                                        }
                                        case EditCerDate: {  
                                            string newDate;
                                            while (true) {
                                                try {
                                                    cout << "Enter new Certificate Date (dd/mm/yyyy): ";
                                                    getline(cin, newDate);

                                                    if (!isValidDate(newDate)) {
                                                        throw DateException();
                                                    }
                                                    certificates[i]->setDate(newDate);
                                                    break;
                                                }
                                                catch (const DateException& e) {
                                                    cerr << "Error: " << e.what() << endl;
                                                }
                                            }
                                            break;
                                        }
                                        case 0:
                                            cout << "Finished editing certificate.\n";
                                            return;
                                        default:
                                            cout << "Invalid choice! Please try again.\n";
                                    }
                                }
                            }
                        }

                        if (!found) {
                            cout << "No certificate found with ID " << selectedId << ".\n";
                        }
                        break;
                    }
                    case FinishEdit:
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
        
        //for testing
        void addTestCertificate(int id, const string& name, const string& rank, const string& date) {
            if (manageIdCer.find(id) != manageIdCer.end()) {
                cout << "Certificate ID " << id << " already exists for this employee. Skipping..." << endl;
                return;
            }

            unique_ptr<Certificate> cert = make_unique<Certificate>(id, name, rank, date);
            manageIdCer.insert(cert->getId());
            certificates.push_back(move(cert));
            cout << "Certificate " << id << " added successfully to employee ID " << this->ID << "." << endl;
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
        
        Experience(string fullName, string birthDay, string phone, string email,int ExpInYear, string ProSkill)
        : Employee(fullName, birthDay, phone, email, employeeType::Experience), ExpInYear(ExpInYear), ProSkill(ProSkill) {
            this->type = employeeType::Experience;
        }

        string getType() override {
            return "Experience";
        }
    
        void detailEmployee() override {
            displayBasicInfo();
            cout << left
                << setw(26) << ExpInYear
                << setw(20) << ProSkill
                << endl;
            displayCertificates();
        }

        void inputExperienceInYear(bool isInput){
            while (true) {
                try {
                    isInput == true ? cout << "Enter Experience In Year: " : cout << "Enter new Experience In Year: ";
                    cin >> this->ExpInYear;
                    if (cin.fail() || ExpInYear < 0) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw MustBeNumberException();
                    }
                    break;
                }
                catch (const MustBeNumberException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }
        }

        void inputProSkill(bool isInput){
            while (true) {
                try {
                    isInput == true ? cout << "Enter Pro Skill: " : cout << "Enter new Pro Skill: ";
                    getline(cin, this->ProSkill);
                    if (!isValidString(this->ProSkill)) {
                        throw MustBeStringException();
                    }
                    break;
                }
                catch (const MustBeStringException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }
        }

        void inputEmployee() override{
            Employee::inputEmployee();
            inputExperienceInYear(true);
            inputProSkill(true);
        }

        void editEmployee() override {
            Employee::editEmployee();
            
            int choice;
            while (true) {
                detailEmployee();
                cout << "Select the field to edit:\n";
                cout << "6. Experience In Year\n";
                cout << "7. Pro Skill\n";
                cout << "0. Finish Editing\n";
                cout << "Your choice: ";
                cin >> choice;

                switch (choice) {
                    case EditExpInYear: { 
                        inputExperienceInYear(false);
                        break;
                    }
                    case EditProSkill: { 
                        inputProSkill(false);
                        break;
                    }
                    case FinishEdit:
                        cout << "Finished editing.\n";
                        return;
                    default:
                        cout << "Invalid choice! Please select again.\n";
                }
            }
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
        
        Fresher(string fullName, string birthDay, string phone, string email, string Graduation_date, string Graduation_rank, string Education)
        : Employee(fullName, birthDay, phone, email, employeeType::Fresher), Graduation_date(Graduation_date), Graduation_rank(Graduation_rank), Education(Education) {
            this->type = employeeType::Fresher;
        }

        string getType() override {
            return "Fresher";
        }
        
        void detailEmployee() override {
            displayBasicInfo();
            cout << left                       
                << setw(26) << Graduation_date                        
                << setw(27) << Graduation_rank                        
                << setw(30) << Education                               
                << endl;
            displayCertificates();
        }

        void inputGraduationDate(bool isInput){
            while (true) {
                try {
                    isInput == true ? cout << "Enter Graduation Date: " : cout << "Enter new Graduation Date: ";
                    cin >> this->Graduation_date;
                    if (!isValidDate(this->Graduation_date)) {
                        throw DateException();
                    }
                    break;
                }
                catch (const DateException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }
        }

        void inputGraduationRank(bool isInput){
            while (true) {
                try {
                    isInput == true ? cout << "Enter Graduation Rank: " : cout << "Enter new Graduation Rank: ";
                    cin.ignore();
                    getline(cin, this->Graduation_rank);
                    if (!isValidString(this->Graduation_rank)) {
                        throw MustBeStringException();
                    }
                    break;
                }
                catch (const MustBeStringException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }
        }

        void inputEducation(bool isInput){
            while (true) {
                try {
                    isInput == true ? cout << "Enter Education: " : cout << "Enter new Education: ";
                    getline(cin, this->Education);
                    if (!isValidString(this->Education)) {
                        throw MustBeStringException();
                    }
                    break;
                }
                catch (const MustBeStringException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }
        }

        void inputEmployee() override{
            Employee::inputEmployee();
            inputGraduationDate(true);
            inputGraduationRank(true);
            inputEducation(true);
        }

        void editEmployee() override {
            Employee::editEmployee();
            
            int choice;
            while (true) {
                detailEmployee();
                cout << "Select the field to edit:\n";
                cout << "6. Graduation Date\n";
                cout << "7. Graduation Rank\n";
                cout << "8. Education\n";
                cout << "0. Finish Editing\n";
                cout << "Your choice: ";
                cin >> choice;

                switch (choice) {
                    case EditGraduationDate: {  
                        inputGraduationDate(false);
                        break;
                    }
                    case EditGraduationRank: {  
                        inputGraduationRank(false);
                        break;
                    }
                    case EditEducation: {  
                        inputEducation(false);
                        break;
                    }
                    case FinishEdit:
                        cout << "Finished editing.\n";
                        return;
                    default:
                        cout << "Invalid choice! Please select again.\n";
                }
            }
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

        Intern(string fullName, string birthDay, string phone, string email, string Majors, int Semester, string University_name)
        : Employee(fullName, birthDay, phone, email, employeeType::Intern), Majors(Majors), Semester(Semester), University_name(University_name) {
            this->type = employeeType::Intern;
        }

        string getType() override {
            return "Intern";
        }
        
        void detailEmployee() override {
            displayBasicInfo();
            cout << left
                << setw(26) << Majors
                << setw(27) << Semester
                << setw(30) << University_name
                << endl;
            displayCertificates();
        }

        void inputMajors(bool isInput){
            while (true) {
                try {
                    isInput == true ? cout << "Enter Majors: " : cout << "Enter new Majors: ";
                    cin.ignore();
                    getline(cin, this->Majors);
                    if (!isValidString(this->Majors)) {
                        throw MustBeStringException();
                    }
                    break;
                }
                catch (const MustBeStringException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }
        }

        void inputSemester(bool isInput){
            while (true) {
                try {
                    isInput == true ? cout << "Enter Semester: " : cout << "Enter new Semester: ";
                    cin >> this->Semester;
                    if (cin.fail() || Semester < 0) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw MustBeNumberException();
                    }
                    break;
                }
                catch (const MustBeNumberException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }
        }

        void inputUniversityName(bool isInput){
            while (true) {
                try {
                    isInput == true ? cout << "Enter University Name: " : cout << "Enter new University Name: ";
                    cin.ignore();
                    getline(cin, this->University_name);
                    if (!isValidString(this->University_name)) {
                        throw MustBeStringException();
                    }
                    break;
                }
                catch (const MustBeStringException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }
        }

        void inputEmployee() override{
            Employee::inputEmployee();
            inputMajors(true);
            inputSemester(true);
            inputUniversityName(true);
        }

        void editEmployee() override {
            Employee::editEmployee();
            
            int choice;
            while (true) {
                detailEmployee();
                cout << "Select the field to edit:\n";
                cout << "6. Majors\n";
                cout << "7. Semester\n";
                cout << "8. University Name\n";
                cout << "0. Finish Editing\n";
                cout << "Your choice: ";
                cin >> choice;

                switch (choice) {
                    case EditMajors: {  
                        inputMajors(false);
                        break;
                    }
                    case EditSemester: {  
                        inputSemester(false);
                        break;
                    }
                    case EditUniversityName: {  
                        inputUniversityName(false);
                        break;
                    }
                    case FinishEdit:
                        cout << "Finished editing.\n";
                        return;
                    default:
                        cout << "Invalid choice! Please select again.\n";
                }
            }
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

        void addEmployeeByType(employeeType type) {
            int num;
            cout << "Number of employees to add: ";
            cin >> num;
            
            for (int i = 0; i < num; ++i) {
                shared_ptr<Employee> employee;

                switch (type) {
                    case employeeType::Experience:
                        employee = make_shared<Experience>();
                        break;
                    case employeeType::Fresher:
                        employee = make_shared<Fresher>();
                        break;
                    case employeeType::Intern:
                        employee = make_shared<Intern>();
                        break;
                    default:
                        cout << "Invalid employee type." << endl;
                        return;
                }

                cout << "Enter information for employee " << Employee::employeeTypeToString(type) << " " << i + 1 << ":" << endl;
                employee->inputEmployee();
                addEmployee(employee);
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

        void settingDisplay(){
            cout << left
                 << setw(10) << "ID"
                 << setw(20) << "Employee Type"
                 << setw(20) << "Full Name"
                 << setw(15) << "BirthDay"
                 << setw(15) << "Phone"
                 << setw(20) << "Email";
        }

        void displayEmployee(){
            settingDisplay();
            cout << left
                 << setw(20) << "ExpInYear/GradDate/Majors-"
                 << setw(20) << "ProSkill/GradRank/Semester-"
                 << setw(30) << "Education/University"
                 << endl;
            cout << string(170, '-') << endl;
            for (size_t i = 0; i < listEmployees.size(); ++i) { 
                shared_ptr<Employee> doc = listEmployees[i];  
                doc->detailEmployee();
            }
            cout << string(170, '-') << endl;
        }   

        void displayExperience(){
            settingDisplay();
            cout << left
                 << setw(26) << "ExpInYear"
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

        void displayIntern(){
            settingDisplay();
            cout << left
                 << setw(26) << "Majors"
                 << setw(27) << "Semester"
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

        void displayFresher(){
            settingDisplay();
            cout << left
                 << setw(26) << "Graduation Date"
                 << setw(27) << "Graduation Rank"
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

};

void createSampleEmployees(EmployeeManager& manager) {

    shared_ptr<Employee> emp1 = make_shared<Experience>("Nguyen Van A", "01/01/1990", "0123456789", "a@gmail.com", 5, "Java");
    manager.addEmployee(emp1);
    //ues testAddCertificate to add certificate for testing
    emp1->addTestCertificate(101, "Java Certification", "Advanced", "10/10/2020");

    shared_ptr<Employee> emp2 = make_shared<Fresher>("Tran Van B", "15/05/1995", "0987654321", "b@gmail.com", "20/06/2020", "Good", "HUST");
    manager.addEmployee(emp2);
    emp2->addTestCertificate(102, "C++ Certification", "Intermediate", "15/05/2020");
    emp2->addTestCertificate(103, "Python Certification", "Advanced", "20/06/2020");

    shared_ptr<Employee> emp3 = make_shared<Intern>("Le Thi C", "10/10/2000", "0912345678", "c@gmail.com", "Software Engineering", 5, "NEU");
    manager.addEmployee(emp3);
    
}



int main() {
    EmployeeManager manager;
    int choice;
    //test
    createSampleEmployees(manager);

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
            cout << "0. Exit program" << endl;
            cout << "Your choice: ";
            
            cin >> choice;

            if (cin.fail()) {  
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                throw MenuException();
            }

            switch (choice) {
                case AddEmployee: {
                    int typeInput;
                    string input;
                    bool check = false;

                    while (!check) {
                        try {
                            cout << "0. Add Experience" << endl;
                            cout << "1. Add Fresher" << endl;
                            cout << "2. Add Intern" << endl;
                            cout << "Enter \"exit\" to back to menu" << endl;
                            cout << "Enter your choice: ";
                            cin >> input;

                            if(input == "exit"){
                                cout << "Returning to the main menu..." << endl;
                                break;
                            }

                            if (!regex_match(input, regex("[0-2]"))) {
                                throw MenuAddEmployeeException();
                            }

                            typeInput = stoi(input);
                            employeeType type = static_cast<employeeType>(typeInput);
                            manager.addEmployeeByType(type);
                            check = true;  
                        }
                        catch (const MenuAddEmployeeException& e) {
                            cerr << "Error: " << e.what() << endl;
                        }
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
                case Exit:
                    cout << "Exiting program..." << endl;
                    return 0;
                default:
                    throw MenuException();
            }
        } catch (const MenuException& e) {
            cerr << "Error: " << e.what() << endl;
        } catch (const exception& e) {
            cerr << "Unexpected Error: " << e.what() << endl;
        }
    }

    return 0;
}
