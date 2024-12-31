#include "candidate_manager.h"

void CandidateManager::addCandidate(shared_ptr<Candidate> candidate){
    if (!Candidate::recycledIds.empty())
    {
        int recycleId = *Candidate::recycledIds.begin();
        Candidate::recycledIds.erase(Candidate::recycledIds.begin());
        listCandidates.insert(listCandidates.begin() + (recycleId - 1), candidate);
    }
    else
    {
        listCandidates.push_back(candidate);
    }
}

void CandidateManager::addCandidateByType(CandidateType type) {
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

void CandidateManager::displayCandidate()
{
    cout << left
         << setw(5) << "ID"
         << setw(16) << "Block"
         << setw(16) << "Name"
         << setw(16) << "Address"
         << setw(20) << "Priority Level"
         << setw(40) << "Subject Combination"
         << endl;
    cout << string(100, '-') << endl;
    for (size_t i = 0; i < listCandidates.size(); ++i)
    {
        shared_ptr<Candidate> &candidate = listCandidates[i];
        candidate->detailCandidate();
    }
    cout << string(100, '-') << endl;
}

void CandidateManager::searchDocumentById(int id)
{
    bool found = false;
    for (size_t i = 0; i < listCandidates.size(); ++i)
    {
        shared_ptr<Candidate> &candidate = listCandidates[i];
        if (candidate->getId() == id)
        {
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
    if (!found)
    {
        cout << "No candidate of id " << id << " found." << endl;
    }
}