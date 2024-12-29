#include "candidate_a.h"

CandidateA::CandidateA(){}
CandidateA::CandidateA(string name, string address, int priorityLevel)
    : Candidate(name, address, priorityLevel) {}

void CandidateA::detailCandidate() {
    cout << left
         << setw(5) << getId()
         << setw(16) << "Candidate A"
         << setw(16) << getName()
         << setw(16) << getAddress()
         << setw(20) << getPriorityLevel()
         << setw(40) << "Math, Physics, Chemistry"
         << endl;
}

string CandidateA::getBlock ()
{
    return "Candidate A";
}
