#ifndef FACULTY_H
#define FACULTY_H

#include "student_university.h"

class Faculty{
private:
    string facultyName;
    vector<shared_ptr<Student>> listStudents;

public:
    Faculty();

    Faculty(string);

    string getFacultyName();

    void addStudent(shared_ptr<Student>);

    void addStudentByType();

    void checkIsRegularById(string);

    float getAverageScoreById(string, string);

    int displayTotalRegularStudents();

    float findStudentHighestEntryScore();

    void listPartTimeStudentsByLocation(string);

    void listStudentsAbove8InLatestSemester();

    void findStudentHighestSemesterScore();

    void sortStudentsByTypeAndYear();

    void countStudentsByYear();

    void displayStudents();

};

#endif