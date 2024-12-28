#include "magazine.h"

Magazine::Magazine() : issueNumber(0), issueMonth(""){}

Magazine::Magazine(int idDoc, string publisherName, int editionNumber, int issueNumber, string issueMonth)
            : Document(idDoc, publisherName, editionNumber), issueNumber(issueNumber), issueMonth(issueMonth) {}

void Magazine::detailDocument() {
    cout << left
         << setw(10) << getId()
         << setw(10) << "Magazine"
         << setw(16) << getPublisherName()
         << setw(10) << getEditionNumber()
         << setw(40) << issueNumber
         << setw(10) << issueMonth
         << endl;
}

void Magazine::addDocument() {
    Document::addDocument();
    cout << "Enter issue number: ";
    cin >> this->issueNumber;
    cout << "Enter issue month: ";
    cin >> this->issueMonth;
}

string Magazine::getType() {
    return "Magazine";
}
