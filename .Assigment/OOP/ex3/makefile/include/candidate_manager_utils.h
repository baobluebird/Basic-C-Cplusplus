#ifndef CANDIDATE_MANAGER_UTILS_H
#define CANDIDATE_MANAGER_UTILS_H

#include "candidate_manager.h"
#include "candidate_a.h"
#include "candidate_b.h"
#include "candidate_c.h"

#define AddCandidate 1
#define DisplayCandidate 2
#define SearchById 3

enum class CandidateType {
    CandidateA = 1,
    CandidateB,
    CandidateC
};

void addCandidateA(CandidateManager& manager);
void addCandidateB(CandidateManager& manager);
void addCandidateC(CandidateManager& manager);

#endif
