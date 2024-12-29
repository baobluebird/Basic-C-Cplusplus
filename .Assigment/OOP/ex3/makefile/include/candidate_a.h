#ifndef CANDIDATE_A_H
#define CANDIDATE_A_H

#include "candidate.h"

class CandidateA : public Candidate{
    public:
        CandidateA();
        CandidateA(string, string, int);
    
        void detailCandidate() override ;

        string getBlock() override;
};

#endif
