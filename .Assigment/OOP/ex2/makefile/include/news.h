#ifndef NEWS_H
#define NEWS_H

#include "document.h"

class News : public Document {
private:
    string releaseDay;

public:
    News();
    News(int, string, int, string);

    void detailDocument() override;
    
    void addDocument() override;

    string getType() override;
};

#endif
