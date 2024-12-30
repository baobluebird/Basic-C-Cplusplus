#ifndef DOCUMENT_MANAGER_H
#define DOCUMENT_MANAGER_H

#include "document.h"


class DocumentManager {
private:
    vector<shared_ptr<Document>> listDocuments;

public:
    void addDocument(shared_ptr<Document> );
    
    void deleteDocumentById(int);

    void displayDocument();

    void searchDocumentByType(string);
};

#endif
