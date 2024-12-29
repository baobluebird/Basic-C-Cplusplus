#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "document.h"

class Magazine : public Document {
private:
    int issueNumber;
    string issueMonth;

public:
    Magazine();
    Magazine(string, int, int, string);

    void detailDocument() override;

    void inputDocument() override;
    
    string getType() override;
};

#endif
