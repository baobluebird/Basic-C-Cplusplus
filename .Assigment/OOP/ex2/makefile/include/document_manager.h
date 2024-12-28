#ifndef DOCUMENT_MANAGER_H
#define DOCUMENT_MANAGER_H

#include "document.h"


class DocumentManager {
private:
    vector<unique_ptr<Document>> listDocuments;

public:
    void addDocument(unique_ptr<Document> );
    
    void deleteDocumentById(int);

    void displayDocument();

    void searchDocumentByType(string);
};

#endif
