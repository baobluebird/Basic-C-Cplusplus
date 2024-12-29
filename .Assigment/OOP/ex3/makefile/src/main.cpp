#include "candidate_manager_utils.h"

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
