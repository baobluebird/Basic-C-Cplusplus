#ifndef BOOK_H
#define BOOK_H

#include "document.h"

class Book : public Document {
private:
    string authorName;
    int pageNumber;
public:
    Book();
    Book(int, string, int, string, int);

    void detailDocument() override;

    void addDocument() override;

    string getType() override;
};

#endif
