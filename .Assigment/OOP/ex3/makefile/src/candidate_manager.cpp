#include "candidate_manager.h"

void CandidateManager::addCandidate(unique_ptr<Candidate> candidate){
    if (!Candidate::recycledIds.empty())
    {
        int recycleId = *Candidate::recycledIds.begin();
        Candidate::recycledIds.erase(Candidate::recycledIds.begin());
        listCandidates.insert(listCandidates.begin() + (recycleId - 1), move(candidate));
    }
    else
    {
        listCandidates.push_back(move(candidate));
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
        unique_ptr<Candidate> &candidate = listCandidates[i];
        candidate->detailCandidate();
    }
    cout << string(100, '-') << endl;
}

void CandidateManager::searchDocumentById(int id)
{
    bool found = false;
    for (size_t i = 0; i < listCandidates.size(); ++i)
    {
        unique_ptr<Candidate> &candidate = listCandidates[i];
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