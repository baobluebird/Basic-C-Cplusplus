#include "document_manager.h"

void DocumentManager::addDocument(shared_ptr<Document> document) {
    if (!Document::recycledIds.empty()) {
        int recycleId = *Document::recycledIds.begin();
        Document::recycledIds.erase(Document::recycledIds.begin());
        listDocuments.insert(listDocuments.begin() + (recycleId - 1), document);
    } else {
        listDocuments.push_back(document);
    }
}

void DocumentManager::deleteDocumentById(int id) {
    int sizeList = listDocuments.size();
    if (id < 1 || id > sizeList) {
        cout << "ID not found" << endl;
        return;
    }

    listDocuments.erase(listDocuments.begin() + (id - 1));
    cout << "Delete successfully" << endl;
    return;
}

void DocumentManager::displayDocument() {
    cout << left
         << setw(10) << "ID"
         << setw(10) << "Type"
         << setw(16) << "PublisherName"
         << setw(10) << "Edition"
         << setw(40) << "AuthorName/IssueNumber/ReleaseDay"
         << setw(20) << "PageNumber/IssueMonth"
         << endl;
    cout << string(65, '-') << endl;
    for (shared_ptr<Document> doc : listDocuments) {
        doc->detailDocument();
    }
    cout << string(65, '-') << endl;
}

void DocumentManager::searchDocumentByType(string type) {
    bool found = false;
    for (shared_ptr<Document> doc : listDocuments) {
        if (doc->getType() == type) {
            doc->detailDocument();
            found = true;
        }
    }
    if (!found) {
        cout << "No documents of type " << type << " found." << endl;
    }
}

