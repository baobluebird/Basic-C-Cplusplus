#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <iostream>
#include <vector>
#include <memory>
#include <set>
#include <iomanip> 
#include <string>
using namespace std;

class Candidate{
    private:
        int id;
        string name;
        string address;
        int priorityLevel;
        static int count;
    public:
        static set<int> manageId;
        static set<int> recycledIds;  

        Candidate();

        Candidate(string, string, int);

        void generateUniqueId();

        int getId();

        string getName();

        string getAddress();

        int getPriorityLevel();

        void inputCandidate();

        virtual void detailCandidate() = 0;

        virtual string getBlock() = 0;

        virtual ~Candidate();
};

#endif