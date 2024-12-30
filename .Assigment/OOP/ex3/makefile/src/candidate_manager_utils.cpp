#include "candidate_manager_utils.h"

void addCandidateA(CandidateManager& manager){
    int num;
    cout << "Number of Candidate A to add: ";
    cin >> num;
    for(int i = 0; i < num; ++i){
        cout << "Enter information for candidate a " << i + 1 << ":" << endl;
        unique_ptr<Candidate> document = make_unique<CandidateA>();
        document->inputCandidate();
        manager.addCandidate(move(document));
    }
}

void addCandidateB(CandidateManager& manager){
    int num;
    cout << "Number of Candidate B to add: ";
    cin >> num;
    for(int i = 0; i < num; ++i){
        cout << "Enter information for candidate b " << i + 1 << ":" << endl;
        unique_ptr<Candidate> document = make_unique<CandidateB>();
        document->inputCandidate();
        manager.addCandidate(move(document));
    }
}

void addCandidateC(CandidateManager& manager){
    int num;
    cout << "Number of Candidate C to add: ";
    cin >> num;
    for(int i = 0; i < num; ++i){
        cout << "Enter information for candidate c " << i + 1 << ":" << endl;
        unique_ptr<Candidate> document = make_unique<CandidateC>();
        document->inputCandidate();
        manager.addCandidate(move(document));
    }
}
