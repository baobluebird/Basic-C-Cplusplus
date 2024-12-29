#ifndef CANDIDATE_C_H
#define CANDIDATE_C_H

#include "candidate.h"

class CandidateC : public Candidate{
    public:
        CandidateC();
        CandidateC(string, string, int);
    
        void detailCandidate() override ;

        string getBlock() override;
};

#endif
