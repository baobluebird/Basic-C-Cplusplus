#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H
#include "students.h"

class StudentManager {
private:    
    vector<shared_ptr<Student>> students;

public:
    void addStudent(shared_ptr<Student>);

    void readFromFile(const string&, string);

    void displayRecruitedStudents(int);

    void displayAllStudents();
};

#endif