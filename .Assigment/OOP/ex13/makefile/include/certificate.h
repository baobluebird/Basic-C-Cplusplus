#ifndef CERTIFICATE_H
#define CERTIFICATE_H
#include <iostream>
#include <string>
using namespace std;
class Certificate {
    private:
        int CertificatedID;
        string CertificateName;
        string CertificateRank;
        string CertificatedDate;
    public:
        Certificate(); 

        Certificate(int , string , string , string );

        void addCertificate();

        void infoCertificates();
};

#endif