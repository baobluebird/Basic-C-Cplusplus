#include "candidate.h"

set<int> Candidate::manageId;
set<int> Candidate::recycledIds;
int Candidate::count = 1;

Candidate::Candidate() : name(""), address(""), priorityLevel(0){
    generateUniqueId();
}

Candidate::Candidate(string name, string address, int priorityLevel){
    generateUniqueId();
    this->name = name;
    this->address = address;
    this->priorityLevel = priorityLevel;
}

void Candidate::generateUniqueId(){
    if (!recycledIds.empty())
    {
        this->id = *recycledIds.begin();
    }
    else
    {
        this->id = count++;
    }
    manageId.insert(this->id);
}

int Candidate::getId(){
    return this->id;
}

string Candidate::getName(){
    return this->name;
}

string Candidate::getAddress(){
    return this->address;
}

int Candidate::getPriorityLevel(){
    return this->priorityLevel;
}

void Candidate::inputCandidate(){
    cout << "Enter name: ";
    cin >> this->name;
    cout << "Enter address: ";
    cin >> this->address;
    cout << "Enter priority level: ";
    cin >> this->priorityLevel;
}

Candidate::~Candidate()
{
    manageId.erase(this->id);
    recycledIds.insert(this->id);
    cout << "Destructor of ID: " << this->id << endl;
}
