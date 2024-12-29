#include "candidate_b.h"

CandidateB::CandidateB() {}
CandidateB::CandidateB(string name, string address, int priorityLevel)
    : Candidate(name, address, priorityLevel) {}

void CandidateB::detailCandidate() {
    cout << left
         << setw(5) << getId()
         << setw(16) << "Candidate B"
         << setw(16) << getName()
         << setw(16) << getAddress()
         << setw(20) << getPriorityLevel()
         << setw(40) << "Math, Physics, Chemistry"
         << endl;
}

string CandidateB::getBlock(){
    return "Candidate B";
}
