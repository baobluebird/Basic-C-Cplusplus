#include "document.h"

int Document::count = 1;
set<int> Document::manageId;
set<int> Document::recycledIds;

Document::Document() : publisherName(""), editionNumber(0) {
    generateUniqueId();
}

Document::Document(int idDoc, string publisherName, int editionNumber){
    generateUniqueId();
    this->publisherName = publisherName;
    this->editionNumber = editionNumber;
}
    
void Document::generateUniqueId() {
    if(!recycledIds.empty()){
        this->idDoc = *recycledIds.begin();
    }else{
        this->idDoc = count++;
    }
    manageId.insert(this->idDoc);
}       

void Document::detailDocument() {
    cout << left 
         << setw(10) << this->idDoc
         << setw(20) << this->publisherName
         << setw(15) << this->editionNumber << endl;
}

int Document::getId() {
    return this->idDoc;
}

string Document::getPublisherName() {
    return this->publisherName;
}

int Document::getEditionNumber() {
    return this->editionNumber;
}

void Document::addDocument() {
    cout << "Enter publisher name: ";
    cin >> this->publisherName;
    cout << "Enter edition number: ";
    cin >> this->editionNumber;
}

Document::~Document() {
    manageId.erase(this->idDoc);
    recycledIds.insert(this->idDoc);
    cout << "Destructor of ID: " << this->idDoc << endl;
}


