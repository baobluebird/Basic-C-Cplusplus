#include "certificate.h"
#include "utils_employees.h"
#include <regex>

Certificate::Certificate() : CertificatedID(0), CertificateName(""), CertificateRank(""), CertificatedDate("") {}

Certificate::Certificate(int id, string name, string rank, string date)
    : CertificatedID(id), CertificateName(name), CertificateRank(rank), CertificatedDate(date) {}

bool Certificate::isValidString(const string& str) {
    return !str.empty() && regex_match(str, regex("^(?=.*[A-Za-zÀ-ỹ])[A-Za-zÀ-ỹ0-9\\s]+$"));
}

bool Certificate::isValidDate(const string& birthday) {
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

int Certificate::getId(){
    return this->CertificatedID;
}

void Certificate::setId(int id){
    this->CertificatedID = id;
}

void Certificate::setName(string name){
    this->CertificateName = name;
}

void Certificate::setRank(string rank){
    this->CertificateRank = rank;
}

void Certificate::setDate(string date){
    this->CertificatedDate = date;
}

void Certificate::addCertificate(int id) {
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

void Certificate::infoCertificates(){
    cout << "ID: " << this->CertificatedID << ", Name: " << this->CertificateName
         << ", Rank: " << this->CertificateRank << ", Date: " << this->CertificatedDate << endl;
}