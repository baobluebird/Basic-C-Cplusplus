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
protected:
    int idDoc;
    string publisherName;
    int editionNumber;
    static int count;
public:
    static set<int> manageId;
    static set<int> recycledIds;
    Document();
    Document(int, string, int);

    void generateUniqueId();

    virtual void detailDocument();

    int getId();

    string getPublisherName();

    int getEditionNumber();

    virtual void addDocument();
    
    virtual string getType() = 0;

    virtual ~Document();
};

#endif
