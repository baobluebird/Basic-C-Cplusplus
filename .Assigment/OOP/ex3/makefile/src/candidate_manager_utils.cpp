#include "candidate_manager_utils.h"

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
