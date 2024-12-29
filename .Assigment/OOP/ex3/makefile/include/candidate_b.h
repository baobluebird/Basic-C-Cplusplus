#ifndef CANDIDATE_B_H
#define CANDIDATE_B_H

#include "candidate.h"

class CandidateB : public Candidate{
    public:
        CandidateB();
        CandidateB(string, string, int);
    
        void detailCandidate() override ;

        string getBlock() override;
};

#endif
