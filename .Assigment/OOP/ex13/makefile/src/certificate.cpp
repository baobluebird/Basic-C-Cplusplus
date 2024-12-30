#include "certificate.h"

Certificate::Certificate() : CertificatedID(0), CertificateName(""), CertificateRank(""), CertificatedDate("") {}

Certificate::Certificate(int id, string name, string rank, string date)
    : CertificatedID(id), CertificateName(name), CertificateRank(rank), CertificatedDate(date) {}
    
void Certificate::addCertificate(){
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

void Certificate::infoCertificates(){
    cout << "ID: " << this->CertificatedID << ", Name: " << this->CertificateName
         << ", Rank: " << this->CertificateRank << ", Date: " << this->CertificatedDate << endl;
}