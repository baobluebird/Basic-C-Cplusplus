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
        vector<shared_ptr<Candidate>> listCandidates;
    public:

        void addCandidate(shared_ptr<Candidate> candidate) {
            if (!Candidate::recycledIds.empty()) {
                int recycleId = *Candidate::recycledIds.begin();
                Candidate::recycledIds.erase(Candidate::recycledIds.begin());
                listCandidates.insert(listCandidates.begin() + (recycleId - 1), candidate);
            } else {
                listCandidates.push_back(candidate);  
            }
        }

        void addCandidateByType(CandidateType type) {
            int num;
            cout << "Number of candidates to add: ";
            cin >> num;
            cin.ignore();
            string typeStr;

            for (int i = 0; i < num; ++i) {
                shared_ptr<Candidate> candidate;

                switch (type) {
                    case CandidateType::CandidateA:
                        typeStr = "Candidate A";
                        candidate = make_shared<CandidateA>();
                        break;
                    case CandidateType::CandidateB:
                        typeStr = "Candidate B";
                        candidate = make_shared<CandidateB>();
                        break;
                    case CandidateType::CandidateC:
                        typeStr = "Candidate C";
                        candidate = make_shared<CandidateC>();
                        break;
                    default:
                        cout << "Invalid candidate type." << endl;
                        return;
                }

                cout << "Enter information for candidate " << typeStr << " " << i + 1 << ":" << endl;
                candidate->inputCandidate();
                addCandidate(candidate);
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
                shared_ptr<Candidate>& candidate = listCandidates[i];  
                candidate->detailCandidate();
            }
            cout << string(100, '-') << endl;
        }

        void searchDocumentById(int id) {
            bool found = false;
            for (size_t i = 0; i < listCandidates.size(); ++i) { 
                shared_ptr<Candidate>& candidate = listCandidates[i];   
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

                if (typeInput < 1 || typeInput > 3) {
                    cout << "Invalid candidate type. Please enter again (1-3)." << endl;
                    break;
                }

                CandidateType type = static_cast<CandidateType>(typeInput);
                manager.addCandidateByType(type);
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
