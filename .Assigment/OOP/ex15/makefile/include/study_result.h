#ifndef STUDY_RESULT_H
#define STUDY_RESULT_H
#include "utils_university.h"
#include "exception.h"
using namespace std;
class StudyResult{
private:
    string Semester;
    float avgScore;
protected:
    bool isValidString(const string&);
    bool isValidScore(const float&);
public:

    StudyResult();

    StudyResult(string, float);

    string getSemesterName();

    float getAvgScore();

    void inputSemester();

    void inputAvgScore();

    void addStudyResult();

    void displayStudyResult();
};

#endif