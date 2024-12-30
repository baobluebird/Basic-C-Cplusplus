#include "employees.h"

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

set<int> Employee::manageId;
set<int> Employee::recycledIds;
int Employee::employeeCount = 1;

Employee::Employee() : fullName(""), birthDay(""), phone(""), email(""){
    generateUniqueId();
}

Employee::Employee(string fullName, string birthDay, string phone, string email, employeeType type){
    generateUniqueId();
    this->fullName = fullName;
    this->birthDay = birthDay;
    this->phone = phone;
    this->email = email;
    this->type = type;
}

void Employee::generateUniqueId(){
    if (!recycledIds.empty())
    {
        this->ID = *recycledIds.begin();
    }
    else
    {
        this->ID = employeeCount++;
    }
    manageId.insert(this->ID);
}

int Employee::getId(){
    return this->ID;
}

string Employee::getFullName(){
    return this->fullName;
}

string Employee::getBirthDay(){
    return this->birthDay;
}

string Employee::getPhone(){
    return this->phone;
}

string Employee::getEmail(){
    return this->email;
}

bool Employee::isValidBirthDay(const string &birthday){
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

bool Employee::isValidPhone(const string &phone){
    regex pattern(R"(^0\d{9}$)"); 
    return regex_match(phone, pattern);
}

bool Employee::isValidEmail(const string &email){
    regex pattern(R"((\w+)(\.|\w)*@(\w+)(\.\w+)+)");
    return regex_match(email, pattern);
}

bool Employee::isValidFullName(const string &fullName){
    regex pattern(R"(^[A-Za-zÀ-ỹ\s]+$)");
    return regex_match(fullName, pattern) && !fullName.empty();
}

string Employee::employeeTypeToString(employeeType type) {
    switch (type) {
        case employeeType::Experience: return "Experience";
        case employeeType::Fresher: return "Fresher";
        case employeeType::Intern: return "Intern";
        default: return "Unknown";
    }
}

void Employee::inputEmployee(){
    while (true){
        try{
            cout << "Enter Full Name: ";
            cin.ignore();
            getline(cin, this->fullName);
            if (!isValidFullName(this->fullName)){
                throw FullNameException();
            }
            break;
        }
        catch (const FullNameException &e){
            cerr << "Error: " << e.what() << endl;
            cout << "Name must not contain numbers or special characters. Please try again.\n";
        }
    }

    while (true){
        try{
            cout << "Enter Birthday (dd/mm/yyyy): ";
            cin >> this->birthDay;
            if (!isValidBirthDay(this->birthDay)){
                throw BirthDayException();
            }
            break;
        }
        catch (const BirthDayException &e){
            cerr << "Error: " << e.what() << endl;
        }
    }

    while (true){
        try{
            cout << "Enter Phone: ";
            string phoneInput;
            cin >> phoneInput;
            if (!isValidPhone(phoneInput)){
                throw PhoneException();
            }
            this->phone = phoneInput;
            break;
        }
        catch (const PhoneException &e){
            cerr << "Error: " << e.what() << endl;
        }
    }

    while (true){
        try{
            cout << "Enter Email: ";
            cin >> this->email;
            if (!isValidEmail(this->email)){
                throw EmailException();
            }
            break;
        }
        catch (const EmailException &e){
            cerr << "Error: " << e.what() << endl;
        }
    }
    int num;
    cout << "Number of Certificate to add: ";
    cin >> num;
    cin.ignore();
    for (int i = 0; i < num; ++i){
        cout << "Enter information for Certificate " << i + 1 << ":" << endl;
        unique_ptr<Certificate> cer = make_unique<Certificate>();
        cer->addCertificate();
        certificates.push_back(move(cer));
    }
}

void Employee::displayCertificates(){
    cout << string(60, '+') << endl;
    cout << "Certificates of " << fullName << ":" << endl;
    for (const auto &cert : certificates){
        cert->infoCertificates();
    }
    cout << string(60, '+') << endl;
}

void Employee::editEmployee(){
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

Employee::~Employee(){
    manageId.erase(this->ID);
    recycledIds.insert(this->ID);
    cout << "Destructor of ID: " << this->ID << endl;
}