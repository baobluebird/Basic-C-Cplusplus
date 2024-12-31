#ifndef DOCUMENT_MANAGER_H
#define DOCUMENT_MANAGER_H

#include "document.h"
#include "book.h"
#include "magazine.h"
#include "news.h"
enum class DocumentType {
    Book = 1,
    Magazine,
    News
};

class DocumentManager {
private:
    vector<shared_ptr<Document>> listDocuments;

public:
    void addDocument(shared_ptr<Document> );
    
    void addDocumentByType(DocumentType type);

    void deleteDocumentById(int);

    void displayDocument();

    void searchDocumentByType(string);
};

#endif
