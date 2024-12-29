#ifndef CANDIDATE_MANAGER_H
#define CANDIDATE_MANAGER_H

#include "candidate.h"

class CandidateManager{
    private:
        vector<unique_ptr<Candidate>> listCandidates;
    public:

        void addCandidate(unique_ptr<Candidate>);

        void displayCandidate();

        void searchDocumentById(int);
};

#endif  