#include "document.h"

int Document::count = 1;
set<int> Document::manageId;
set<int> Document::recycledIds;

Document::Document() : publisherName(""), editionNumber(0) {
    generateUniqueId();
}

Document::Document(string publisherName, int editionNumber){
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


int Document::getId() {
    return this->idDoc;
}

string Document::getPublisherName() {
    return this->publisherName;
}

int Document::getEditionNumber() {
    return this->editionNumber;
}

void Document::inputDocument() {
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


