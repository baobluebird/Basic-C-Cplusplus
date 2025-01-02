#ifndef STUDENT_UNIVERSITY_H
#define STUDENT_UNIVERSITY_H
#include "study_result.h"
#include "exception.h"
class Student{
private:
    string studentID;
    string fullName;
    string dob;
    int yearEnrolled;
    float entryScore;
    vector<unique_ptr<StudyResult>> studyResults;
    static set<string> usedStudentIDs;
protected:
    bool isValidDate(const string&);

    bool isValidFullName(const string&);

    bool isValidYear(const string&);

    bool isValidScore(const float&);

    bool isValidString(const string&);

public:
    
    Student();

    Student(string, string, string, int, float);

    string getStudentID();

    int getYearEnrolled();

    float getEntryScore();
    
    string getFullName();

    float getAverageScore(string);

    void inputName();

    void inputBirthday();

    void inputYearEnrolled();

    void inputEntryScore();

    void addStudyResult(string, float);

    void displayStudyResults();

    float getLatestSemesterScoreAbove8();

    float getHighestSemesterScore();

    virtual void inputStudent();

    virtual void displayStudent();

    virtual string getLinkedLocation();

    virtual bool isRegular() = 0;

    virtual ~Student() {}
};

#endif