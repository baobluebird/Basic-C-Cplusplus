#ifndef CANDIDATE_MANAGER_H
#define CANDIDATE_MANAGER_H

#include "candidate.h"
#include "candidate_a.h"
#include "candidate_b.h"
#include "candidate_c.h"

enum class CandidateType {
    CandidateA = 1,
    CandidateB,
    CandidateC
};
class CandidateManager{
    private:
        vector<shared_ptr<Candidate>> listCandidates;
    public:

        void addCandidate(shared_ptr<Candidate>);

        void addCandidateByType(CandidateType); 

        void displayCandidate();

        void searchDocumentById(int);
};

#endif  