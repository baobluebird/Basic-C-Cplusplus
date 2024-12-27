// Một thư viện cần quản lý các tài liệu bao gồm Sách, Tạp chí, Báo. Mỗi tài liệu gồm có các thuộc tính sau: Mã tài liệu(Mã tài liệu là duy nhất), Tên nhà xuất bản, số bản phát hành.

// Các loại sách cần quản lý thêm các thuộc tính: tên tác giả, số trang.

// Các tạp chí cần quản lý thêm: Số phát hành, tháng phát hành.

// Các báo cần quản lý thêm: Ngày phát hành.

// Yêu cầu 1: Xây dựng các lớp để quản lý tài liệu cho thư viện một cách hiệu quả.

// Yêu cầu 2: Xây dựng lớp QuanLySach có các chức năng sau

// Thêm mới tài liêu: Sách, tạp chí, báo.
// Xoá tài liệu theo mã tài liệu.
// Hiện thị thông tin về tài liệu.
// Tìm kiếm tài liệu theo loại: Sách, tạp chí, báo.
// Thoát khỏi chương trình.
#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>
#include <set>
#include <iomanip> 

#define AddDoc 1
#define DeleteDoc 2
#define DisplayDoc 3
#define SearchByType 4
enum class DocumentType {
    Book = 1,
    Magazine,
    News
};

using namespace std;

class Document{
    private:
        int idDoc;
        string publisherName;
        int editionNumber;
        static int count;
        static unordered_set<int> manageId;
    public:
        static set<int> recycledIds;  

        Document() : publisherName(""), editionNumber(0) {
            generateUniqueId();
        }
        Document(int idDoc, string publisherName, int editionNumber){
            generateUniqueId();
            this->publisherName = publisherName;
            this->editionNumber = editionNumber;
        }

        void generateUniqueId() {
            if(!recycledIds.empty()){
                this->idDoc = *recycledIds.begin();
                recycledIds.erase(recycledIds.begin());
            }else{
                this->idDoc = count++;
            }
            manageId.insert(this->idDoc);
        }

        virtual void detailDocument() {
            cout << left 
                 << setw(10) << this->idDoc
                 << setw(20) << this->publisherName
                 << setw(15) << this->editionNumber
                 << endl;
        }

        int getId(){
            return this->idDoc;
        }

        string getPublisherName(){
            return this->publisherName;
        }

        int getEditionNumber(){
            return this->editionNumber;
        }

        virtual void addDocument(){
            cout << "Enter publisher name: " << endl;
            cin >> this->publisherName;
            cout << "Enter edition number: " << endl;
            cin >> this->editionNumber;

        }

        virtual string getType() = 0;

        virtual ~Document(){
            manageId.erase(this->idDoc);
            recycledIds.insert(this->idDoc);
        }
};

unordered_set<int> Document::manageId;
set<int> Document::recycledIds;
int Document::count = 1;

class Book : public Document{
    private:
        string authorName;
        int pageNumber;
    public:
        Book() : authorName(""), pageNumber(0) {}
        Book(int idDoc, string publisherName, int editionNumber, string authorName, int pageNumber)
            : Document(idDoc, publisherName, editionNumber), authorName(authorName), pageNumber(pageNumber) {}
    
        void detailDocument() override {
                cout << left
                     << setw(10) << getId()
                     << setw(10) << "Book"
                     << setw(16) << getPublisherName()
                     << setw(10) << getEditionNumber()
                     << setw(40) << authorName
                     << setw(10) << pageNumber
                     << endl;
        }


        void addDocument(){
            Document::addDocument();
            cout << "Enter author name: " << endl;
            cin >> this->authorName;
            cout << "Enter page number: " << endl;
            cin >> this->pageNumber;
        }

        string getType(){
            return "Book";
        }

};



class Magazine : public Document{
    private:
        int issueNumber;
        string issueMonth;
    public: 
        Magazine() : issueNumber(0), issueMonth(""){}
        Magazine(int idDoc, string publisherName, int editionNumber, string authorName, int issueNumber, string issueMonth)
            : Document(idDoc, publisherName, editionNumber), issueNumber(issueNumber), issueMonth(issueMonth) {}
        
        void detailDocument() override {
                cout << left
                     << setw(10) << getId()
                     << setw(10) << "Magazine"
                     << setw(16) << getPublisherName()
                     << setw(10) << getEditionNumber()
                     << setw(40) << issueNumber
                     << setw(10) << issueMonth
                     << endl;
        }


        void addDocument(){
            Document::addDocument();
            cout << "Enter issue number: " << endl;
            cin >> this->issueNumber;
            cout << "Enter issue month: " << endl;
            cin >> this->issueMonth;
        }

        string getType(){
            return "Magazine";
        }
};

class News : public Document{
    private:
        string releaseDay;
    public:
        News() : releaseDay(""){}
        News(int idDoc, string publisherName, int editionNumber, string releaseDay)
            : Document(idDoc, publisherName, editionNumber), releaseDay(releaseDay) {}
        
        void detailDocument() override {
            cout << left
                 << setw(10) << getId()
                 << setw(10) << "News"
                 << setw(16) << getPublisherName()
                 << setw(10) << getEditionNumber()
                 << setw(40) << releaseDay
                 << endl;
        }

        void addDocument(){
            Document::addDocument();
            cout << "Enter release day: " << endl;
            cin >> this->releaseDay;

        }

        string getType(){
            return "News";
        }
}; 

class Library{
    private:
        vector<shared_ptr<Document>> listDocuments;
    public:

        void addDocument(shared_ptr<Document> document){
            if(!Document::recycledIds.empty()){
                int recycleId = *Document::recycledIds.begin();
                //Document::recycledIds.erase(Document::recycledIds.begin());
                listDocuments.insert(listDocuments.begin() + recycleId - 1, document);
            }else{
                listDocuments.push_back(document);
            }
            
        }

        bool deleteDocumentById(int id){
            for(size_t i = 0; i < listDocuments.size(); ++i){
                if(listDocuments[i]->getId() == id){
                    listDocuments.erase(listDocuments.begin() + i);
                    cout << "Delete successfully";
                    return true;
                }
            }
            cout << "Id not found" << endl;
            return false;
        }

        void displayDocument(){
            cout << left
                 << setw(10) << "ID"
                 << setw(10) << "Type"
                 << setw(16) << "PublisherName"
                 << setw(10) << "Edition"
                 << setw(40) << "AuthorName/IssueNumber/ReleaseDay"
                 << setw(20) << "PageNumber/IssueMonth"
                 << endl;
            cout << string(65, '-') << endl;
            for(shared_ptr<Document> doc : listDocuments){
                doc->detailDocument();
            }
            cout << string(65, '-') << endl;
        }

        void searchDocumentByType(string type){
            bool found = false;
            for(shared_ptr<Document> doc : listDocuments){
                if(doc->getType() == type){
                    doc->detailDocument();
                    found = true;
                }
            }
            if (!found) {
                cout << "No documents of type " << type << " found." << endl;
            }
        }
};

void addBook(Library& manager){
    int num;
    cout << "Number of Book to add: ";
    cin >> num;
    for(int i = 0; i < num; ++i){
        cout << "Enter information for book " << i + 1 << ":" << endl;
        shared_ptr<Document> document = make_shared<Book>();
        document->addDocument();
        manager.addDocument(document);
    }
}
void addMagazine(Library& manager){
    int num;
    cout << "Number of Magazine to add: ";
    cin >> num;
    for(int i = 0; i < num; ++i){
        cout << "Enter information for magazine " << i + 1 << ":" << endl;
        shared_ptr<Document> document = make_shared<Magazine>();
        document->addDocument();
        manager.addDocument(document);
    }
}
void addNews(Library& manager){
    int num;
    cout << "Number of News to add: ";
    cin >> num;
    for(int i = 0; i < num; ++i){
        cout << "Enter information for news " << i + 1 << ":" << endl;
        shared_ptr<Document> document = make_shared<News>();
        document->addDocument();
        manager.addDocument(document);
    }
}



int main() {
    Library manager;
    int choice;

    while(1) {
        cout << "------- Menu -------" << endl;
        cout << "1. Add Document" << endl;
        cout << "2. Delete document by id" << endl;
        cout << "3. Display all document" << endl;
        cout << "4. Search document by type" << endl;
        cout << "0. Exit program" << endl;
        cin >> choice;

        if(choice == 0) {
            break;
        }

        switch (choice) {
            case AddDoc: {
                cout << "1. Add Book" << endl;
                cout << "2. Add Magazine" << endl;
                cout << "3. Add News" << endl;
                int typeInput; 
                cin >> typeInput;
                DocumentType type = static_cast<DocumentType>(typeInput);
                shared_ptr<Document> document;
                switch (type) {
                    case DocumentType::Book: {
                        addBook(manager);
                        break;
                    }
                    case DocumentType::Magazine: {
                        addMagazine(manager);
                        break;
                    }
                    case DocumentType::News: {
                        addNews(manager);
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case DeleteDoc: {
                int id;
                cout << "Enter document's id to delete: ";
                cin >> id;
                manager.deleteDocumentById(id);
                break;
            }
            case DisplayDoc: {
                cout << "--------- All Documents ---------" << endl;
                manager.displayDocument();
                break;
            }
            case SearchByType: {
                string type;
                cout << "Enter document's type to search: ";
                cin >> type;
                manager.searchDocumentByType(type);
                break;
            }
            default:
                break;
        }
    }

    return 0;
}
