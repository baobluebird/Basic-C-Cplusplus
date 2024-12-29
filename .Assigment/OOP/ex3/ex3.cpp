// Các thí sinh dự thi đại học bao gồm các thí sinh thi khối A, B, và khối C. Các thí sinh cần quản lý các thông tin sau: Số báo danh, họ tên, địa chỉ, mức ưu tiên.

// Thí sinh thi khối A thi các môn: Toán, Lý, Hoá.

// Thí sinh thi khối B thi các môn: Toán, Hoá, Sinh.

// Thí sinh thi khối C thi các môn: Văn, Sử, Địa.

// Yêu cầu 1: Xây dựng các lớp để quản lý các thi sinh dự thi đại học.

// Yêu cầu 2: Xây dựng lớp TuyenSinh có các chức năng:

// Thêm mới thí sinh.
// Hiện thị thông tin của thí sinh và khối thi của thí sinh.
// Tìm kiếm theo số báo danh.
// Thoát khỏi chương trình.
#include <iostream>
#include <vector>
#include <memory>
#include <set>
#include <iomanip> 
#include <string>
using namespace std;

#define AddCandidate 1
#define DisplayCandidate 2
#define SearchById 3

enum class CandidateType {
    CandidateA = 1,
    CandidateB,
    CandidateC
};



class Candidate{
    private:
        int id;
        string name;
        string address;
        int priorityLevel;
        static int count;
    public:
        static set<int> manageId;
        static set<int> recycledIds;  

        Candidate() : name(""), address(""), priorityLevel(0) {
            generateUniqueId();
        }

        Candidate(string name, string address, int priorityLevel){
            generateUniqueId();
            this->name = name;
            this->address = address;
            this->priorityLevel = priorityLevel;
        }

        void generateUniqueId() {
            if(!recycledIds.empty()){
                this->id = *recycledIds.begin();
            }else{
                this->id = count++;
            }
            manageId.insert(this->id);
        }

        int getId(){
            return this->id;
        }

        string getName(){
            return this->name;
        }

        string getAddress(){
            return this->address;
        }

        int getPriorityLevel(){
            return this->priorityLevel;
        }

        

        void inputCandidate(){
            cout << "Enter name: ";
            cin >> this->name;
            cout << "Enter address: ";
            cin >> this->address;
            cout << "Enter priority level: ";
            cin >> this->priorityLevel;
        }

        virtual void detailCandidate() = 0;

        virtual string getBlock() = 0;

        virtual ~Candidate(){
            manageId.erase(this->id);
            recycledIds.insert(this->id);
            cout << "Destructor of ID: " << this->id << endl;
        }
};

set<int> Candidate::manageId;
set<int> Candidate::recycledIds;
int Candidate::count = 1;

class CandidateA : public Candidate{
    public:
        CandidateA(){}
        CandidateA(string name, string address, int priorityLevel)
            : Candidate(name, address, priorityLevel) {}
    
        void detailCandidate() override {
                cout << left
                     << setw(5) << getId()
                     << setw(16) << "Candidate A"
                     << setw(16) << getName()
                     << setw(16) << getAddress()
                     << setw(20) << getPriorityLevel()
                     << setw(40) << "Math, Physics, Chemistry"
                     << endl;
        }

        string getBlock(){
            return "Candidate A";
        }

};

class CandidateB : public Candidate{
    public: 
        CandidateB(){}
        CandidateB(string name, string address, int priorityLevel)
            : Candidate(name, address, priorityLevel){}
        
        void detailCandidate() override {
                cout << left
                     << setw(5) << getId()
                     << setw(16) << "Candidate B"
                     << setw(16) << getName()
                     << setw(16) << getAddress()
                     << setw(20) << getPriorityLevel()
                     << setw(40) << "Math, Chemistry, Biology"
                     << endl;
        }

        string getBlock(){
            return "Candidate B";
        }
};

class CandidateC: public Candidate{
    public:
        CandidateC(){}
         CandidateC(string name, string address, int priorityLevel)
            : Candidate(name, address, priorityLevel){}
        
        void detailCandidate() override {
                cout << left
                     << setw(5) << getId()
                     << setw(16) << "Candidate C"
                     << setw(16) << getName()
                     << setw(16) << getAddress()
                     << setw(20) << getPriorityLevel()
                     << setw(40) << "Literature, History, Geography"
                     << endl;
        }

        string getBlock(){
            return "Candidate C";
        }
}; 

class CandidateManager{
    private:
        vector<unique_ptr<Candidate>> listCandidates;
    public:

        void addCandidate(unique_ptr<Candidate> candidate) {
            if (!Candidate::recycledIds.empty()) {
                int recycleId = *Candidate::recycledIds.begin();
                Candidate::recycledIds.erase(Candidate::recycledIds.begin());
                listCandidates.insert(listCandidates.begin() + (recycleId - 1), move(candidate));
            } else {
                listCandidates.push_back(move(candidate));  
            }
        }


        void displayCandidate(){
            cout << left
                 << setw(5) << "ID"
                 << setw(16) << "Block"
                 << setw(16) << "Name"
                 << setw(16) << "Address"
                 << setw(20) << "Priority Level"
                 << setw(40) << "Subject Combination"
                 << endl;
            cout << string(100, '-') << endl;
            for (size_t i = 0; i < listCandidates.size(); ++i) { 
                unique_ptr<Candidate>& candidate = listCandidates[i];  
                candidate->detailCandidate();
            }
            cout << string(100, '-') << endl;
        }

        void searchDocumentById(int id) {
            bool found = false;
            for (size_t i = 0; i < listCandidates.size(); ++i) { 
                unique_ptr<Candidate>& candidate = listCandidates[i];   
                if (candidate->getId() == id) {
                cout << left
                     << setw(5) << "ID"
                     << setw(16) << "Block"
                     << setw(16) << "Name"
                     << setw(16) << "Address"
                     << setw(20) << "Priority Level"
                     << setw(40) << "Subject Combination"
                     << endl;
                    candidate->detailCandidate();
                    found = true;
                }
            }
            if (!found) {
                cout << "No candidate of id " << id << " found." << endl;
            }
        }
};

void addCandidateA(CandidateManager& manager){
    int num;
    cout << "Number of Candidate A to add: ";
    cin >> num;
    for(int i = 0; i < num; ++i){
        cout << "Enter information for book " << i + 1 << ":" << endl;
        unique_ptr<Candidate> document = make_unique<CandidateA>();
        document->inputCandidate();
        manager.addCandidate(move(document));
    }
}

void addCandidateB(CandidateManager& manager){
    int num;
    cout << "Number of Magazine to add: ";
    cin >> num;
    for(int i = 0; i < num; ++i){
        cout << "Enter information for magazine " << i + 1 << ":" << endl;
        unique_ptr<Candidate> document = make_unique<CandidateB>();
        document->inputCandidate();
        manager.addCandidate(move(document));
    }
}

void addCandidateC(CandidateManager& manager){
    int num;
    cout << "Number of News to add: ";
    cin >> num;
    for(int i = 0; i < num; ++i){
        cout << "Enter information for news " << i + 1 << ":" << endl;
        unique_ptr<Candidate> document = make_unique<CandidateC>();
        document->inputCandidate();
        manager.addCandidate(move(document));
    }
}



int main() {
    CandidateManager manager;
    int choice;

    while(1) {
        cout << "------- Menu -------" << endl;
        cout << "1. Add Candidate" << endl;
        cout << "2. Display all document" << endl;
        cout << "3. Search document by id" << endl;
        cout << "0. Exit program" << endl;
        cin >> choice;

        if(choice == 0) {
            break;
        }

        switch (choice) {
            case AddCandidate: {
                cout << "1. Add Candidate A" << endl;
                cout << "2. Add Candidate B" << endl;
                cout << "3. Add Candidate C" << endl;
                int typeInput; 
                cin >> typeInput;
                CandidateType type = static_cast<CandidateType>(typeInput);
                switch (type) {
                    case CandidateType::CandidateA: {
                        addCandidateA(manager);
                        break;
                    }
                    case CandidateType::CandidateB: {
                        addCandidateB(manager);
                        break;
                    }
                    case CandidateType::CandidateC: {
                        addCandidateC(manager);
                        break;
                    }
                    default:
                        break;
                }
                break;
            }

            case DisplayCandidate: {
                cout << "--------- All Candidates ---------" << endl;
                manager.displayCandidate();
                break;
            }
            case SearchById: {
                int id;
                cout << "Enter candidate's id to search: ";
                cin >> id;
                manager.searchDocumentById(id);
                break;
            }
            default:
                break;
        }
    }

    return 0;
}
