#include "news.h"

News::News() : releaseDay(""){}

News::News( string publisherName, int editionNumber, string releaseDay)
            : Document(publisherName, editionNumber), releaseDay(releaseDay) {}

void News::detailDocument() {
    cout << left
         << setw(10) << getId()
         << setw(10) << "News"
         << setw(16) << getPublisherName()
         << setw(10) << getEditionNumber()
         << setw(40) << releaseDay
         << endl;
}

void News::inputDocument() {
    Document::inputDocument();
    cout << "Enter release day: ";
    cin >> this->releaseDay;
}

string News::getType() {
    return "News";
}
