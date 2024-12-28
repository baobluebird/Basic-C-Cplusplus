#include "book.h"

Book::Book() : authorName(""), pageNumber(0) {}

Book::Book(int idDoc, string publisherName, int editionNumber, string authorName, int pageNumber)
    : Document(idDoc, publisherName, editionNumber), authorName(authorName), pageNumber(pageNumber) {}

void Book::detailDocument() {
    cout << left
         << setw(10) << getId()
         << setw(10) << "Book"
         << setw(16) << getPublisherName()
         << setw(10) << getEditionNumber()
         << setw(40) << authorName
         << setw(10) << pageNumber
         << endl;
}

void Book::addDocument() {
    Document::addDocument();
    cout << "Enter author name: ";
    cin >> authorName;
    cout << "Enter page number: ";
    cin >> pageNumber;
}

string Book::getType() {
    return "Book";
}
