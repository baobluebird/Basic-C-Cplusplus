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
    public:
        static set<int> manageId;
        static set<int> recycledIds;  

        Document() : publisherName(""), editionNumber(0) {
            generateUniqueId();
        }

        Document(string publisherName, int editionNumber){
            generateUniqueId();
            this->publisherName = publisherName;
            this->editionNumber = editionNumber;
        }

        void generateUniqueId() {
            if(!recycledIds.empty()){
                this->idDoc = *recycledIds.begin();
            }else{
                this->idDoc = count++;
            }
            manageId.insert(this->idDoc);
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

        virtual void inputDocument(){
            cout << "Enter publisher name: ";
            cin >> this->publisherName;
            cout << "Enter edition number: ";
            cin >> this->editionNumber;
        }

        virtual void detailDocument() = 0;

        virtual string getType() = 0;

        virtual ~Document(){
            manageId.erase(this->idDoc);
            recycledIds.insert(this->idDoc);
            cout << "Destructor of ID: " << this->idDoc << endl;
        }
};
set<int> Document::manageId;
set<int> Document::recycledIds;
int Document::count = 1;

class Book : public Document{
    private:
        string authorName;
        int pageNumber;
    public:
        Book() : authorName(""), pageNumber(0) {}
        Book(string publisherName, int editionNumber, string authorName, int pageNumber)
            : Document( publisherName, editionNumber), authorName(authorName), pageNumber(pageNumber) {}
    
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

        void inputDocument(){
            Document::inputDocument();
            cout << "Enter author name: ";
            cin >> this->authorName;
            cout << "Enter page number: ";
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
        Magazine(string publisherName, int editionNumber, int issueNumber, string issueMonth)
            : Document(publisherName, editionNumber), issueNumber(issueNumber), issueMonth(issueMonth) {}
        
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


        void inputDocument(){
            Document::inputDocument();
            cout << "Enter issue number: ";
            cin >> this->issueNumber;
            cout << "Enter issue month: ";
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
        News(string publisherName, int editionNumber, string releaseDay)
            : Document(publisherName, editionNumber), releaseDay(releaseDay) {}
        
        void detailDocument() override {
            cout << left
                 << setw(10) << getId()
                 << setw(10) << "News"
                 << setw(16) << getPublisherName()
                 << setw(10) << getEditionNumber()
                 << setw(40) << releaseDay
                 << endl;
        }

        void inputDocument(){
            Document::inputDocument();
            cout << "Enter release day: ";
            cin >> this->releaseDay;

        }

        string getType(){
            return "News";
        }
}; 

class DocumentManager{
    private:
        vector<unique_ptr<Document>> listDocuments;
    public:

        void addDocument(unique_ptr<Document> document) {
            if (!Document::recycledIds.empty()) {
                int recycleId = *Document::recycledIds.begin();
                Document::recycledIds.erase(Document::recycledIds.begin());
                listDocuments.insert(listDocuments.begin() + (recycleId - 1), move(document));
            } else {
                listDocuments.push_back(move(document));  
            }
        }

        void addDocumentByType(DocumentType type) {
            int num;
            cout << "Number of documents to add: ";
            cin >> num;
            cin.ignore();
            string typeStr;
            
            for (int i = 0; i < num; ++i) {
                unique_ptr<Document> document;
                
                switch (type) {
                    case DocumentType::Book:
                        typeStr = "Book";
                        document = make_unique<Book>();
                        break;
                    case DocumentType::Magazine:
                        typeStr = "Magazine";
                        document = make_unique<Magazine>();
                        break;
                    case DocumentType::News:
                        typeStr = "News";
                        document = make_unique<News>();
                        break;
                    default:
                        cout << "Invalid document type." << endl;
                        return;
                }

                cout << "Enter information for document " << typeStr << " " << i + 1 << ":" << endl;
                document->inputDocument();
                addDocument(move(document));
            }
        }


        bool deleteDocumentById(int id) {
            if (id < 1 || id > Document::manageId.size()) {
                cout << "ID not found" << endl;
                return false;
            }

            listDocuments.erase(listDocuments.begin() + (id - 1));

            cout << "Delete successfully" << endl;
            return true;
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
            for (size_t i = 0; i < listDocuments.size(); ++i) { 
                unique_ptr<Document>& doc = listDocuments[i];  
                doc->detailDocument();
            }
            cout << string(65, '-') << endl;
        }

        void searchDocumentByType(string type) {
            bool found = false;
            for (size_t i = 0; i < listDocuments.size(); ++i) { 
                unique_ptr<Document>& doc = listDocuments[i];   
                if (doc->getType() == type) {
                    doc->detailDocument();
                    found = true;
                }
            }
            if (!found) {
                cout << "No documents of type " << type << " found." << endl;
            }
        }
};

int main() {
    DocumentManager manager;
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
                
                if (typeInput < 1 || typeInput > 3) {
                    cout << "Invalid document type. Please enter again (1-3)." << endl;
                    break;
                }

                DocumentType type = static_cast<DocumentType>(typeInput);
                manager.addDocumentByType(type);
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
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}
