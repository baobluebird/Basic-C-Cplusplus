#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <set>
#include <vector>
#include <memory>

using namespace std;

class Document {
private:
    int idDoc;
    string publisherName;
    int editionNumber;
    static int count;
public:
    static set<int> manageId;
    static set<int> recycledIds;
    Document();
    Document(string, int);

    void generateUniqueId();

    int getId();

    string getPublisherName();

    int getEditionNumber();

    virtual void inputDocument();

    virtual void detailDocument() = 0;
    
    virtual string getType() = 0;

    virtual ~Document();
};

#endif
