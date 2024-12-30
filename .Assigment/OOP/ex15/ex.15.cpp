#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stdexcept>
#include <iomanip>

using namespace std;

class InvalidInputException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid input data!";
    }
};

class StudyResult
{
public:
    string semesterName;
    float avgScore;

    StudyResult(string semesterName, float avgScore)
        : semesterName(semesterName), avgScore(avgScore) {}
};

class Student
{
private:
    string studentID;
    string fullName;
    string dob;
    int yearEnrolled;
    float entryScore;
    vector<StudyResult> studyResults;

public:
    Student(string studentID, string fullName, string dob, int yearEnrolled, float entryScore)
        : studentID(studentID), fullName(fullName), dob(dob), yearEnrolled(yearEnrolled), entryScore(entryScore) {}

    virtual ~Student() {}

    virtual bool isRegular() = 0;

    virtual void input()
    {
        cout << "Enter Student ID: ";
        cin >> studentID;
        cout << "Enter Full Name: ";
        cin.ignore();
        getline(cin, fullName);
        cout << "Enter Date of Birth (dd/mm/yyyy): ";
        cin >> dob;
        cout << "Enter Year of Enrollment: ";
        cin >> yearEnrolled;
        cout << "Enter Entry Score: ";
        cin >> entryScore;

        if (entryScore < 0 || entryScore > 10)
        {
            throw InvalidInputException();
        }

        int n;
        cout << "Number of Study Results: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string semester;
            float score;
            cout << "Enter Semester Name: ";
            cin >> semester;
            cout << "Enter Average Score: ";
            cin >> score;
            studyResults.emplace_back(semester, score);
        }
    }

    virtual void output() const
    {
        cout << "ID: " << studentID << ", Name: " << fullName
             << ", DOB: " << dob << ", Year Enrolled: " << yearEnrolled
             << ", Entry Score: " << entryScore << endl;
    }

    float getAverageScore(const string &semester) const
    {
        for (const auto &result : studyResults)
        {
            if (result.semesterName == semester)
            {
                return result.avgScore;
            }
        }
        return 0.0;
    }

    string getStudentID() const { return studentID; }
    int getYearEnrolled() const { return yearEnrolled; }
    float getEntryScore() const { return entryScore; }
    vector<StudyResult> getStudyResults() const { return studyResults; }
    string getFullName() const { return fullName; }
};

class RegularStudent : public Student
{
public:
    RegularStudent(string studentID, string fullName, string dob, int yearEnrolled, float entryScore)
        : Student(studentID, fullName, dob, yearEnrolled, entryScore) {}

    bool isRegular() override
    {
        return true;
    }

    void output() const override
    {
        Student::output();
        cout << "Type: Regular Student" << endl;
    }
};

class PartTimeStudent : public Student
{
private:
    string linkedLocation;

public:
    PartTimeStudent(string studentID, string fullName, string dob, int yearEnrolled, float entryScore, string linkedLocation)
        : Student(studentID, fullName, dob, yearEnrolled, entryScore), linkedLocation(linkedLocation) {}

    bool isRegular() override
    {
        return false;
    }

    void output() const override
    {
        Student::output();
        cout << "Type: Part-Time Student, Linked Location: " << linkedLocation << endl;
    }

    string getLinkedLocation() const
    {
        return linkedLocation;
    }
};

class Faculty
{
private:
    string facultyName;
    vector<Student *> students;

public:
    Faculty(string facultyName) : facultyName(facultyName) {}

    ~Faculty()
    {
        for (Student *student : students)
        {
            delete student;
        }
    }

    void addStudent(Student *student)
    {
        students.push_back(student);
    }

    int countRegularStudents() const
    {
        return count_if(students.begin(), students.end(), [](Student *s)
                        { return s->isRegular(); });
    }

    Student *getTopEntryScoreStudent() const
    {
        return *max_element(students.begin(), students.end(),
                            [](Student *a, Student *b)
                            { return a->getEntryScore() < b->getEntryScore(); });
    }

    vector<Student *> getPartTimeStudentsByLocation(const string &location) const
    {
        vector<Student *> result;
        for (Student *student : students)
        {
            PartTimeStudent *partTime = dynamic_cast<PartTimeStudent *>(student);
            if (partTime && partTime->getLinkedLocation() == location)
            {
                result.push_back(partTime);
            }
        }
        return result;
    }

    vector<Student *> getHighAchievers() const
    {
        vector<Student *> result;
        for (Student *student : students)
        {
            const auto &results = student->getStudyResults();
            if (!results.empty() && results.back().avgScore >= 8.0)
            {
                result.push_back(student);
            }
        }
        return result;
    }

    void sortStudents()
    {
        sort(students.begin(), students.end(), [](Student *a, Student *b)
             {
            if (a->isRegular() != b->isRegular()) {
                return a->isRegular() > b->isRegular();
            }
            return a->getYearEnrolled() > b->getYearEnrolled(); });
    }

    void displayStatistics() const
    {
        map<int, int> stats;
        for (Student *student : students)
        {
            stats[student->getYearEnrolled()]++;
        }
        for (const auto &pair : stats)
        {
            cout << "Year " << pair.first << ": " << pair.second << " students" << endl;
        }
    }

    void displayStudents() const
    {
        for (Student *student : students)
        {
            student->output();
        }
    }
};

int main(){
    return 0;
}
