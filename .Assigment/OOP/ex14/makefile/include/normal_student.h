#ifndef NORMAL_STUDENT_H
#define NORMAL_STUDENT_H
#include "students.h"

class NormalStudent : public Student {
private:
    int englishScore;
    float entryTestScore;
public:
    NormalStudent() : englishScore(0), entryTestScore(0.0f) {}
    
    NormalStudent(string, string, string, string, string, string, int, float);
        
    void ShowMyInfor() override;

    int getEnglishScore() override;

    float getEntryTestScore() override;

    float getGPA() override;

    string getType() override;

};

#endif