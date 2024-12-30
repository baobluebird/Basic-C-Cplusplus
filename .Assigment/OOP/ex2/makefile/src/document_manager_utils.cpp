#include "document_manager_utils.h"

void addBook(DocumentManager& manager) {
    int num;
    cout << "Number of Book to add: ";
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cout << "Enter information for book " << i + 1 << ":" << endl;
        shared_ptr<Document> document = make_shared<Book>();
        document->inputDocument();
        manager.addDocument(move(document));
    }
}

void addMagazine(DocumentManager& manager) {
    int num;
    cout << "Number of Magazine to add: ";
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cout << "Enter information for magazine " << i + 1 << ":" << endl;
        shared_ptr<Document> document = make_shared<Magazine>();
        document->inputDocument();
        manager.addDocument(move(document));
    }
}

void addNews(DocumentManager& manager) {
    int num;
    cout << "Number of News to add: ";
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cout << "Enter information for news " << i + 1 << ":" << endl;
        shared_ptr<Document> document = make_shared<News>();
        document->inputDocument();
        manager.addDocument(move(document));
    }
}
