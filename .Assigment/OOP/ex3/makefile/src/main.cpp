#include "utils_candidate.h"
#include "candidate_manager.h"

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
