#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "faculty.h"

class University{
private:
    vector<shared_ptr<Faculty>> listFaculties;
public:

    void addFaculty(shared_ptr<Faculty>);
    
    void displayFaculties();

    void checkIsRegularById(string);

    float getAverageScoreById(string, string);

    void displayTotalRegularStudents();

    void findStudentHighestEntryScore();

    void listPartTimeStudentsByLocation(string);

    void listStudentsAbove8InLatestSemester();

    void findStudentHighestSemesterScore();

    void sortStudentsByTypeAndYear();

    void countStudentsByYear();

    void addSampleData();

};

#endif
