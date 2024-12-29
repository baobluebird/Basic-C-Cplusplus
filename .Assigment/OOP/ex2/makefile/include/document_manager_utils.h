#ifndef DOCUMENT_MANAGER_UTILS_H
#define DOCUMENT_MANAGER_UTILS_H

#include "document_manager.h"
#include "book.h"
#include "magazine.h"
#include "news.h"

#define AddDoc 1
#define DeleteDoc 2
#define DisplayDoc 3
#define SearchByType 4

enum class DocumentType {
    Book = 1,
    Magazine,
    News
};

void addBook(DocumentManager& manager);
void addMagazine(DocumentManager& manager);
void addNews(DocumentManager& manager);

#endif
