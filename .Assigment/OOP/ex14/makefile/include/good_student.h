#ifndef GOOD_STUDENT_H
#define GOOD_STUDENT_H
#include "students.h"

class GoodStudent : public Student {
private:
    float gpa;
    string bestRewardName;
public:
    GoodStudent(string, string, string, string, string, string, float, string);
        
    void ShowMyInfor() override;

    float getGPA() override;

    int getEnglishScore() override;

    float getEntryTestScore() override;

    string getType() override;
};

#endif