#include "employees.h"
#include "utils_employees.h"
#include <regex>


set<int> Employee::manageId;
set<int> Employee::recycledIds;
int Employee::employeeCount = 1;

bool Employee::isValidDate(const string& birthday) {
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

bool Employee::isValidPhone(const string& phone) {
    regex pattern(R"(^0\d{9}$)"); 
    return regex_match(phone, pattern);
}

bool Employee::isValidEmail(const string& email) {
    regex pattern(R"((\w+)(\.|\w)*@(\w+)(\.\w+)+)"); 
    return regex_match(email, pattern);
}

bool Employee::isValidFullName(const string& fullName) {
    regex pattern(R"(^[A-Za-zÀ-ỹ ]{3,}$)");
    return regex_match(fullName, pattern);
}

bool Employee::isValidString(const string& str) {
    return !str.empty() && regex_match(str, regex("^[A-Za-zÀ-ỹ\\s]+$"));
}

string Employee::employeeTypeToString(employeeType type) {
    switch (type) {
        case employeeType::Experience: return "Experience";
        case employeeType::Fresher: return "Fresher";
        case employeeType::Intern: return "Intern";
        default: return "Unknown";
    }
}

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
    if (!recycledIds.empty()){
        this->ID = *recycledIds.begin();
    }
    else{
        this->ID = employeeCount++;
    }
    manageId.insert(this->ID);
}

void Employee::inputName(bool isInput){
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

void Employee::inputBirthday(bool isInput){
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

void Employee::inputPhone(bool isInput){
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

void Employee::inputEmail(bool isInput){
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

void Employee::inputCertificates(){
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
        }catch (const MustBeNumberException& e) {
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

void Employee::displayCertificates() {
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

void Employee::displayBasicInfo() {
    cout << left
        << setw(10) << this->ID
        << setw(20) << Employee::employeeTypeToString(this->type)
        << setw(20) << this->fullName
        << setw(15) << this->birthDay
        << setw(15) << this->phone
        << setw(20) << this->email;
}

void Employee::inputEmployee(){
            
    inputName(true);

    inputBirthday(true);

    inputPhone(true);

    inputEmail(true);

    inputCertificates();
            
}

void Employee::editEmployee() {
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

Employee::~Employee(){
    manageId.erase(this->ID);
    recycledIds.insert(this->ID);
    cout << "Destructor of ID: " << this->ID << endl;
}