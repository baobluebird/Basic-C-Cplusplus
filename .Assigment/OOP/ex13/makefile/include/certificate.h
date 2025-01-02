#ifndef CERTIFICATE_H
#define CERTIFICATE_H
#include <iostream>
#include <string>
#include "exception.h"

using namespace std;
class Certificate {
    private:
        int CertificatedID;
        string CertificateName;
        string CertificateRank;
        string CertificatedDate;
    protected:
        bool isValidString(const string&);

        bool isValidDate(const string&);
    public:
        Certificate(); 

        Certificate(int , string , string , string );

        int getId();

        void setId(int);

        void setName(string);

        void setRank(string);

        void setDate(string);

        void addCertificate(int);

        void infoCertificates();
};

#endif