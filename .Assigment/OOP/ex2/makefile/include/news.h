#ifndef NEWS_H
#define NEWS_H

#include "document.h"

class News : public Document {
private:
    string releaseDay;

public:
    News();
    News(string, int, string);

    void detailDocument() override;
    
    void inputDocument() override;

    string getType() override;
};

#endif
