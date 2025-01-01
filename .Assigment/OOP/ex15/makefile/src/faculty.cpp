#include "faculty.h"
#include "regular_student.h"
#include "part_time_student.h"

Faculty::Faculty() : facultyName("") {}

Faculty::Faculty(string facultyName) : facultyName(facultyName) {}

string Faculty::getFacultyName(){
    return facultyName;
}

void Faculty::addStudent(shared_ptr<Student> student){
    listStudents.push_back(student);
}

void Faculty::addStudentByType(){
    cout << "Enter Student Type (1: Regular, 2: Part-Time): ";
    int type;
    cin >> type;
    shared_ptr<Student> student;
    if (type == 1)
    {
        student = make_shared<RegularStudent>();
    }
    else if (type == 2)
    {
        student = make_shared<PartTimeStudent>();
    }
    student->inputStudent();
    addStudent(student);
}

void Faculty::checkIsRegularById(string id){
    cout << "Faculty: " << facultyName << endl;
    for (shared_ptr<Student> student : listStudents)
    {
        if (student->getStudentID() == id)
        {
            if (student->isRegular())
            {
                cout << "Regular Student" << endl;
            }
            else
            {
                cout << "Part-Time Student" << endl;
            }
            return;
        }
    }
    cout << "Student not found" << endl;
}

float Faculty::getAverageScoreById(string id, string semester){
    for (shared_ptr<Student> student : listStudents)
    {
        if (student->getStudentID() == id)
        {
            float avg = student->getAverageScore(semester);
            if (avg != -1)
            {
                cout << "Average Score of " << student->getFullName()
                     << " in semester " << semester << " is: " << avg << endl;
                return avg;
            }
            else
            {
                cout << "No results found for Student ID " << id
                     << " in Semester " << semester << endl;
                return -1;
            }
        }
    }
    return -2;
}

int Faculty::displayTotalRegularStudents(){
    int count = 0;
    for (shared_ptr<Student> student : listStudents)
    {
        if (student->isRegular())
        {
            count++;
        }
    }
    cout << "Total Regular Students in " << facultyName << ": " << count << endl;
    return count;
}

float Faculty::findStudentHighestEntryScore(){
    float maxScore = 0.0;
    shared_ptr<Student> studentMaxScore;
    for (shared_ptr<Student> student : listStudents)
    {
        if (student->getEntryScore() > maxScore)
        {
            maxScore = student->getEntryScore();
            studentMaxScore = student;
        }
    }
    cout << "Student with Highest Entry Score " << maxScore << " in Faculty " << facultyName << " is: " << studentMaxScore->getStudentID() << " - " << studentMaxScore->getFullName() << endl;
    return maxScore;
}

void Faculty::listPartTimeStudentsByLocation(string location){
    for (shared_ptr<Student> student : listStudents)
    {
        if (student->getLinkedLocation() == location)
        {
            student->displayStudent();
        }
    }
}

void Faculty::listStudentsAbove8InLatestSemester(){
    bool found = false;
    cout << "Students with Average Score >= 8.0 in Latest Semester - Faculty: " << facultyName << endl;

    for (shared_ptr<Student> student : listStudents)
    {
        float latestScore = student->getLatestSemesterScoreAbove8();

        if (latestScore != -1)
        {
            student->displayStudent();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No students found with Average Score >= 8.0 in the latest semester in " << facultyName << endl;
    }
}

void Faculty::findStudentHighestSemesterScore(){
    float maxScore = 0.0;
    shared_ptr<Student> topStudent = nullptr;

    for (auto &student : listStudents)
    {
        float studentHighestScore = student->getHighestSemesterScore();
        if (studentHighestScore > maxScore)
        {
            maxScore = studentHighestScore;
            topStudent = student;
        }
    }

    if (topStudent)
    {
        cout << "Student with Highest Semester Score in Faculty " << facultyName << ":" << endl;
        topStudent->displayStudent();
        cout << "Highest Semester Score: " << maxScore << endl;
    }
    else
    {
        cout << "No students found with semester results in Faculty " << facultyName << endl;
    }
}

void Faculty::sortStudentsByTypeAndYear(){
    sort(listStudents.begin(), listStudents.end(), [](const shared_ptr<Student> &a, const shared_ptr<Student> &b)
         {
            if (a->isRegular() != b->isRegular()) {
                return !a->isRegular();  
            }
            return a->getYearEnrolled() > b->getYearEnrolled(); });

    cout << "Sorted students by type and year in Faculty: " << facultyName << endl;
    displayStudents();
}

void Faculty::countStudentsByYear(){
    map<int, int> yearCount;

    for (auto &student : listStudents)
    {
        int year = student->getYearEnrolled();
        yearCount[year]++;
    }

    cout << "Student Enrollment Statistics for Faculty: " << facultyName << endl;
    for (auto &entry : yearCount)
    {
        cout << entry.first << ": " << entry.second << " students" << endl;
    }
}

void Faculty::displayStudents(){
    cout << setw(20) << "Type"
         << setw(10) << "ID"
         << setw(25) << "Full Name"
         << setw(15) << "DOB"
         << setw(10) << "Year"
         << setw(10) << "Entry Score" << endl;
    cout << string(90, '-') << endl;

    for (shared_ptr<Student> student : listStudents)
    {
        student->displayStudent();
    }
}