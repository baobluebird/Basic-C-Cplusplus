#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "document.h"

class Magazine : public Document {
private:
    int issueNumber;
    string issueMonth;

public:
    Magazine();
    Magazine(int, string, int, int, string);

    void detailDocument() override;

    void addDocument() override;
    
    string getType() override;
};

#endif
