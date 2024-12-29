#include "candidate_c.h"

CandidateC::CandidateC() {}
CandidateC::CandidateC(string name, string address, int priorityLevel)
    : Candidate(name, address, priorityLevel) {}

void CandidateC::detailCandidate() {
    cout << left
         << setw(5) << getId()
         << setw(16) << "Candidate C"
         << setw(16) << getName()
         << setw(16) << getAddress()
         << setw(20) << getPriorityLevel()
         << setw(40) << "Math, Physics, Chemistry"
         << endl;
}

string CandidateC::getBlock()
{
    return "Candidate C";
}
