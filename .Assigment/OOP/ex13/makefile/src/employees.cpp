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

set<int> Employee::manageId;
set<int> Employee::recycledIds;
int Employee::employeeCount = 1;

Employee::Employee() : fullName(""), birthDay(""), phone(0), email(""){
    generateUniqueId();
}

Employee::Employee(string fullName, string birthDay, int phone, string email, employeeType type){
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

int Employee::getPhone(){
    return this->phone;
}

string Employee::getEmail(){
    return this->email;
}

bool Employee::isValidBirthDay(const string &birthday){
    regex pattern("^\\d{2}/\\d{2}/\\d{4}$");
    return regex_match(birthday, pattern);
}

bool Employee::isValidPhone(const string &phone){
    return phone.length() == 10 && all_of(phone.begin(), phone.end(), ::isdigit);
}

bool Employee::isValidEmail(const string &email){
    regex pattern(R"((\w+)(\.|\w)*@(\w+)(\.\w+)+)");
    return regex_match(email, pattern);
}

bool Employee::isValidFullName(const string &fullName){
    return !fullName.empty();
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
    while (true)
    {
        try
        {
            cout << "Enter Full Name: ";
            cin.ignore();
            getline(cin, this->fullName);
            if (!isValidFullName(this->fullName))
            {
                throw FullNameException();
            }
            break;
        }
        catch (const FullNameException &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }

    while (true)
    {
        try
        {
            cout << "Enter Birthday (dd/mm/yyyy): ";
            cin >> this->birthDay;
            if (!isValidBirthDay(this->birthDay))
            {
                throw BirthDayException();
            }
            break;
        }
        catch (const BirthDayException &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }

    while (true)
    {
        try
        {
            cout << "Enter Phone: ";
            string phoneInput;
            cin >> phoneInput;
            if (!isValidPhone(phoneInput))
            {
                throw PhoneException();
            }
            this->phone = stoi(phoneInput);
            break;
        }
        catch (const PhoneException &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }

    while (true)
    {
        try
        {
            cout << "Enter Email: ";
            cin >> this->email;
            if (!isValidEmail(this->email))
            {
                throw EmailException();
            }
            break;
        }
        catch (const EmailException &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }
    int num;
    cout << "Number of Certificate to add: ";
    cin >> num;
    for (int i = 0; i < num; ++i)
    {
        cout << "Enter information for Certificate " << i + 1 << ":" << endl;
        unique_ptr<Certificate> cer = make_unique<Certificate>();
        cer->addCertificate();
        certificates.push_back(move(cer));
    }
}

void Employee::displayCertificates(){
    cout << string(60, '+') << endl;
    cout << "Certificates of " << fullName << ":" << endl;
    for (const auto &cert : certificates)
    {
        cert->infoCertificates();
    }
    cout << string(60, '+') << endl;
}

void Employee::editEmployee(){
    inputEmployee();
}

Employee::~Employee(){
    manageId.erase(this->ID);
    recycledIds.insert(this->ID);
    cout << "Destructor of ID: " << this->ID << endl;
}