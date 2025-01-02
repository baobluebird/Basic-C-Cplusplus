#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <regex>
#include <map>
#include <stdexcept>
#include <iomanip>
#include <set>
#include <limits>

//define menu
#define AddStudent 1
#define CheckRegularStudent 2
#define GetAverageScore 3
#define DisplayTotalRegularStudents 4
#define FindStudentHighestEntryScore 5
#define ListPartTimeStudentsByLocation 6
#define ListStudentsAbove8InLatestSemester 7
#define FindStudentHighestSemesterScore 8
#define SortStudentsByTypeAndYear 9
#define CountStudentsByYear 10
#define DisplayStudents 11
#define Exit 0

using namespace std;

class FullNameException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid name. Name must not contain numbers or special characters (Minimum 3 characters)!";
    }
};

class DateException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid date format!";
    }
};

class YearException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid year format!";
    }
};

class ScoreException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid score format!";
    }
};

class MustBeNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid menu choice! Please enter a valid number.";
    }
};

class MustBeStringException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid input! Please enter a valid string (no numbers or empty input).";
    }
};

class MenuException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid menu choice! Please enter a valid number of 0 -> 8.";
    }
};

class StudyResult{
private:
    string Semester;
    float avgScore;
protected:
    bool isValidString(const string& str) {
        return !str.empty() && regex_match(str, regex("^[A-Za-zÀ-ỹ\\s]+$"));
    }
    bool isValidScore(const float& score) {
        return (score >= 0.0f && score <= 10.0f);
    }
public:

    StudyResult() : Semester(""), avgScore(0.0) {}

    StudyResult(string Semester, float avgScore)
        : Semester(Semester), avgScore(avgScore) {}

    string getSemesterName(){
        return this->Semester;
    }

    float getAvgScore(){
        return this->avgScore;
    }

    void inputSemester(){
        cout << "Enter Semester: ";
        cin >> this->Semester;
    }

    void inputAvgScore(){
        while (true) {
            try {
                cout << "Enter Average Score: ";
                cin >> this->avgScore;

                if (cin.fail()) {
                    cin.clear();  
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                    throw MustBeNumberException();
                }

                if (!isValidScore(this->avgScore)) {
                    throw ScoreException();
                }
                break;
            }catch (const MustBeNumberException& e) {
                cerr << "Error: " << e.what() << endl;
            }catch (const ScoreException& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
    }

    void addStudyResult(){
        inputSemester();
        inputAvgScore();
    }

    void displayStudyResult(){
        cout << "Semester: " << this->Semester << ", Average Score: " << this->avgScore << endl;
    }
};

class Student{
private:
    string studentID;
    string fullName;
    string dob;
    int yearEnrolled;
    float entryScore;
    vector<StudyResult> studyResults;
    static set<string> usedStudentIDs;
protected:
    bool isValidDate(const string& birthday) {
        regex pattern(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\d{4}$)"); 
        if (!regex_match(birthday, pattern)) return false;

        int day, month, year;
        sscanf(birthday.c_str(), "%d/%d/%d", &day, &month, &year);

        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
            daysInMonth[2] = 29;
        }

        return day <= daysInMonth[month];
    }

    bool isValidFullName(const string& fullName) {
        regex pattern(R"(^[A-Za-zÀ-ỹ ]{3,}$)");
        return regex_match(fullName, pattern);
    }

    bool isValidYear(const string& year) {
        regex yearPattern(R"(^(19[0-9]{2}|20[0-9]{2})$)");
        return regex_match(year, yearPattern);
    }

    bool isValidScore(const float& score) {
        return (score >= 0.0f && score <= 10.0f);
    }
    
    bool isValidString(const string& str) {
        return !str.empty() && regex_match(str, regex("^[A-Za-zÀ-ỹ\\s]+$"));
    }

public:
    
    Student() : studentID(""), fullName(""), dob(""), yearEnrolled(0), entryScore(0.0) {}

    Student(string studentID, string fullName, string dob, int yearEnrolled, float entryScore)
        : studentID(studentID), fullName(fullName), dob(dob), yearEnrolled(yearEnrolled), entryScore(entryScore) {
            usedStudentIDs.insert(studentID);
        }

    string getStudentID(){
        return this->studentID; 
    }

    int getYearEnrolled(){ 
        return this->yearEnrolled; 
    }

    float getEntryScore(){ 
        return this->entryScore; 
    }
    
    string getFullName(){ 
        return this->fullName; 
    }

    float getAverageScore(string semester){
        for (StudyResult& studyResult : studyResults){
            if (studyResult.getSemesterName() == semester){
                return studyResult.getAvgScore();
            }
        }
        cout << "No results found for semester: " << semester << endl;
        return -1; 
    }

    void inputName(){
        while (true) {
            try {
                cout << "Enter Full Name: ";
                cin.ignore();
                getline(cin, this->fullName);
                if (!isValidFullName(this->fullName)) {
                    throw FullNameException();
                }
                break;
            } catch (const FullNameException& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
    }

    void inputBirthday(){
        while (true) {
            try {
                cout << "Enter Date of Birth (dd/mm/yyyy): ";
                cin >> this->dob;
                if (!isValidDate(this->dob)) {
                    throw DateException();
                }
                break;
            } catch (const DateException& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
    }

    void inputYearEnrolled() {
        while (true) {
            try {
                cout << "Enter Year of Enrollment: ";
                cin >> this->yearEnrolled;
                
                if (cin.fail()) {
                    cin.clear();  
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                    throw MustBeNumberException();
                }

                if (!isValidYear(to_string(yearEnrolled))) {
                    throw YearException();
                }

                break;  
            } catch (const MustBeNumberException& e) {
                cerr << "Error: " << e.what() << endl;
            } catch (const YearException& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
    }

    void inputEntryScore(){
        while (true) {
            try {
                cout << "Enter Entry Score: ";
                cin >> this->entryScore;

                if (cin.fail()) {
                    cin.clear();  
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                    throw MustBeNumberException();
                }

                if (!isValidScore(entryScore)) {
                    throw ScoreException();
                }
                break;
            } catch (const MustBeNumberException& e) {
                cerr << "Error: " << e.what() << endl;
            }catch (const ScoreException& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
    }

    void addStudyResult(string semester, float avgScore) {
        StudyResult newResult(semester, avgScore);
        studyResults.push_back(newResult);
    }

    void displayStudyResults(){
        cout << string(60, '*') << endl;
        cout << "Study Results: " << this->fullName << endl;
        for (StudyResult& studyResult : studyResults){
            studyResult.displayStudyResult();
        }
        cout << string(60, '*') << endl;
    }

    float getLatestSemesterScoreAbove8() {
        if (studyResults.empty()) {
            return -1;
        }
        
        StudyResult latestResult = studyResults[studyResults.size() - 1];


        if (latestResult.getAvgScore() >= 8.0) {
            return latestResult.getAvgScore();
        }

        return -1;
    }

    float getHighestSemesterScore() {
        float highestScore = 0.0;
        for (StudyResult studyResult : studyResults) {
            if (studyResult.getAvgScore() > highestScore) {
                highestScore = studyResult.getAvgScore();
            }
        }
        return highestScore;
    }

    virtual void inputStudent(){
        string id;
        while(true){
            try{
                cout << "Enter Student ID: ";
                cin >> id;
                if(usedStudentIDs.find(id) != usedStudentIDs.end()){
                    throw invalid_argument("Student ID already exists");
                }
                usedStudentIDs.insert(id);
                break;
            }catch(const invalid_argument &e){
                cerr << "Error: " << e.what() << endl;
            }
        }
        this->studentID = id;
        inputName();
        inputBirthday();
        inputYearEnrolled();
        inputEntryScore();

        int n;
        while(true){
            try{
                cout << "Enter number of semesters: ";
                cin >> n;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw MustBeNumberException();
                }
                if(n < 0){
                    throw invalid_argument("Number of semesters must be greater than 0");
                }
                break;
            }catch(const invalid_argument &e){
                cerr << "Error: " << e.what() << endl;
            }catch(const MustBeNumberException &e){
                cerr << "Error: " << e.what() << endl;
            }
        }
        cin.ignore();
        for (int i = 0; i < n; i++){
            StudyResult studyResult;
            studyResult.addStudyResult();
            studyResults.push_back(studyResult);
        }
    }

    virtual void displayStudent() {
        cout << left << setw(10) << studentID
            << setw(25) << fullName
            << setw(15) << dob
            << setw(10) << yearEnrolled
            << setw(10) << entryScore << endl;
    }

    virtual string getLinkedLocation() {
        return ""; 
    }

    virtual bool isRegular() = 0;

    virtual ~Student() {}
};

set<string> Student::usedStudentIDs;

class RegularStudent : public Student{
public:
    RegularStudent(){}

    RegularStudent(string studentID, string fullName, string dob, int yearEnrolled, float entryScore)
        : Student(studentID, fullName, dob, yearEnrolled, entryScore) {}

    bool isRegular() override{
        return true;
    }

    void displayStudent() override {
        cout << left << setw(20) << "Regular Student";
        Student::displayStudent();
        displayStudyResults();
    }

};

class PartTimeStudent : public Student{
private:
    string linkedLocation;

public:
    PartTimeStudent() : linkedLocation("") {}

    PartTimeStudent(string studentID, string fullName, string dob, int yearEnrolled, float entryScore, string linkedLocation)
        : Student(studentID, fullName, dob, yearEnrolled, entryScore), linkedLocation(linkedLocation) {}

    bool isRegular() override{
        return false;
    }

    void inputLinkedLocation(){
        while(true){
            try{
                cout << "Enter Linked Location: ";
                cin.ignore();
                getline(cin, linkedLocation);
                if(!isValidString(linkedLocation)){
                    throw MustBeStringException();
                }
                break;
            }catch(const MustBeStringException &e){
                cerr << "Error: " << e.what() << endl;
            }
        }
    }

    void inputStudent() override{
        Student::inputStudent();
        inputLinkedLocation();
    }

    void displayStudent() override {
        cout << left << setw(20) << "Part-Time Student";
        Student::displayStudent();
        cout << left << setw(20) << "Linked Location: " << linkedLocation << endl;
        displayStudyResults();
    }


    string getLinkedLocation() override{
        return linkedLocation;
    }
};


class Faculty{
private:
    string facultyName;
    vector<shared_ptr<Student>> listStudents;

public:
    Faculty() : facultyName("") {}

    Faculty(string facultyName) : facultyName(facultyName) {}

    string getFacultyName(){
        return facultyName;
    }

    void addStudent(shared_ptr<Student> student){
        listStudents.push_back(student);
    }

    void addStudentByType(){
        cout << "Enter Student Type (1: Regular, 2: Part-Time): ";
        int type;
        cin >> type;
        shared_ptr<Student> student;
        if (type == 1){
            student = make_shared<RegularStudent>();
        }else if (type == 2){
            student = make_shared<PartTimeStudent>();
        }
        student->inputStudent();
        addStudent(student);
    }

    void checkIsRegularById(string& id){
        cout << "Faculty: " << facultyName << endl;
        for (shared_ptr<Student> student : listStudents){
            if (student->getStudentID() == id){
                if (student->isRegular()){
                    cout << "Regular Student" << endl;
                }else{
                    cout << "Part-Time Student" << endl;
                }
                return;
            }
        }
        cout << "Student not found" << endl;
    }

    float getAverageScoreById(string id, string semester) {
        for (shared_ptr<Student> student : listStudents) {
            if (student->getStudentID() == id) {
                float avg = student->getAverageScore(semester);
                if (avg != -1) {
                    cout << "Average Score of " << student->getFullName() 
                        << " in semester " << semester << " is: " << avg << endl;
                    return avg;
                } else {
                    cout << "No results found for Student ID " << id 
                        << " in Semester " << semester << endl;
                    return -1;
                }
            }
        }
        return -2;
    }

    int displayTotalRegularStudents(){
        int count = 0;
        for (shared_ptr<Student> student : listStudents){
            if (student->isRegular()){
                count++;
            }
        }
        cout << "Total Regular Students in " << facultyName << ": " << count << endl;
        return count;
    }

    float findStudentHighestEntryScore(){
        float maxScore = 0.0;
        shared_ptr<Student> studentMaxScore;
        for (shared_ptr<Student> student : listStudents){
            if (student->getEntryScore() > maxScore){
                maxScore = student->getEntryScore();
                studentMaxScore = student;
            }
        }
        cout << "Student with Highest Entry Score " << maxScore << " in Faculty " << facultyName << " is: " << studentMaxScore->getStudentID() << " - " << studentMaxScore->getFullName() << endl;
        return maxScore;
    }

    void listPartTimeStudentsByLocation(string location) {
        for (shared_ptr<Student> student : listStudents) {
            if (student->getLinkedLocation() == location) {
                student->displayStudent();
            }
        }
    }

    void listStudentsAbove8InLatestSemester() {
        bool found = false;
        cout << "Students with Average Score >= 8.0 in Latest Semester - Faculty: " << facultyName << endl;
        
        for (shared_ptr<Student> student : listStudents) {
            float latestScore = student->getLatestSemesterScoreAbove8();
            
            if (latestScore != -1) {
                student->displayStudent();
                found = true;
            }
        }
        
        if (!found) {
            cout << "No students found with Average Score >= 8.0 in the latest semester in " << facultyName << endl;
        }
    }

    void findStudentHighestSemesterScore() {
        float maxScore = 0.0;
        shared_ptr<Student> topStudent = nullptr;

        for (auto& student : listStudents) {
            float studentHighestScore = student->getHighestSemesterScore();
            if (studentHighestScore > maxScore) {
                maxScore = studentHighestScore;
                topStudent = student;
            }
        }

        if (topStudent) {
            cout << "Student with Highest Semester Score in Faculty " << facultyName << ":" << endl;
            topStudent->displayStudent();
            cout << "Highest Semester Score: " << maxScore << endl;
        } else {
            cout << "No students found with semester results in Faculty " << facultyName << endl;
        }
    }

    void sortStudentsByTypeAndYear() {
        sort(listStudents.begin(), listStudents.end(), [](const shared_ptr<Student>& a, const shared_ptr<Student>& b) {
            if (a->isRegular() != b->isRegular()) {
                return !a->isRegular();  
            }
            return a->getYearEnrolled() > b->getYearEnrolled();
        });

        cout << "Sorted students by type and year in Faculty: " << facultyName << endl;
        displayStudents();
    }

    void countStudentsByYear() {
        map<int, int> yearCount;

        for (auto& student : listStudents) {
            int year = student->getYearEnrolled();
            yearCount[year]++;
        }

        cout << "Student Enrollment Statistics for Faculty: " << facultyName << endl;
        for (auto& entry : yearCount) {
            cout << entry.first << ": " << entry.second << " students" << endl;
        }
    }


    void displayStudents() {
        cout << setw(20) << "Type"
             << setw(10) << "ID"
             << setw(25) << "Full Name"
             << setw(15) << "DOB"
             << setw(10) << "Year"
             << setw(10) << "Entry Score" << endl;
        cout << string(90, '-') << endl;

        for (shared_ptr<Student> student : listStudents) {
            student->displayStudent();
        }
    }

};

class University{
private:
    vector<shared_ptr<Faculty>> listFaculties;
public:

    void addFaculty(shared_ptr<Faculty> faculty){
        faculty->addStudentByType();
        listFaculties.push_back(faculty);
    }
    
    void displayFaculties(){
        for (shared_ptr<Faculty> faculty : listFaculties){
            cout << "Faculty: " << faculty->getFacultyName() << endl;
            faculty->displayStudents();
        }
    }

    void checkIsRegularById(string id){
        for (shared_ptr<Faculty> faculty : listFaculties){
            faculty->checkIsRegularById(id);
        }
    }

    float getAverageScoreById(string id, string semester) {
        bool studentFound = false;

        for (shared_ptr<Faculty> faculty : listFaculties) {
            float avg = faculty->getAverageScoreById(id, semester);
            if (avg != -2) {
                studentFound = true;
                return avg;
            }
        }

        if (!studentFound) {
            cout << "Student with ID " << id << " not found in any faculty." << endl;
        }
        return -1;
    }

    void displayTotalRegularStudents(){
        int count = 0;
        for (shared_ptr<Faculty> faculty : listFaculties){
            count += faculty->displayTotalRegularStudents();
        }
        cout << "Total Regular Students: " << count << endl;
    }

    void findStudentHighestEntryScore(){
        float maxScore = 0.0;
        for (shared_ptr<Faculty> faculty : listFaculties){
            maxScore = max(maxScore, faculty->findStudentHighestEntryScore());
        }
        cout << "Highest Entry Score: " << maxScore << endl;
    }

    void listPartTimeStudentsByLocation(string location){
        for (shared_ptr<Faculty> faculty : listFaculties){
            faculty->listPartTimeStudentsByLocation(location);
        }
    }

    void listStudentsAbove8InLatestSemester() {
        for (shared_ptr<Faculty> faculty : listFaculties) {
            faculty->listStudentsAbove8InLatestSemester();
        }
    }

    void findStudentHighestSemesterScore() {
        for (auto& faculty : listFaculties) {
            faculty->findStudentHighestSemesterScore();
        }
    }

    void sortStudentsByTypeAndYear() {
        for (auto& faculty : listFaculties) {
            faculty->sortStudentsByTypeAndYear();
        }
    }

    void countStudentsByYear() {
        for (auto& faculty : listFaculties) {
            faculty->countStudentsByYear();
        }
    }

    void addSampleData() {
        shared_ptr<Faculty> itFaculty = make_shared<Faculty>("Information Technology");
        shared_ptr<Faculty> businessFaculty = make_shared<Faculty>("Business Administration");

        shared_ptr<RegularStudent> student1 = make_shared<RegularStudent>("SV001", "Nguyen Van A", "15/08/2001", 2019, 9.0);
        shared_ptr<RegularStudent> student2 = make_shared<RegularStudent>("SV002", "Tran Thi B", "20/07/2000", 2018, 8.5);

        shared_ptr<PartTimeStudent> student3 = make_shared<PartTimeStudent>("SV003", "Le Van C", "10/06/2002", 2020, 7.0, "HCM City");
        shared_ptr<PartTimeStudent> student4 = make_shared<PartTimeStudent>("SV004", "Pham Thi D", "05/05/2001", 2019, 7.5, "Ha Noi");
        shared_ptr<PartTimeStudent> student5 = make_shared<PartTimeStudent>("SV005", "Le Na", "01/02/2002", 2020, 7.5, "Da Nang");
        
        student1->addStudyResult("1", 8.2);
        student1->addStudyResult("2", 8.5);

        student3->addStudyResult("1", 8.8);
        student3->addStudyResult("2", 7.0);

        student2->addStudyResult("1", 8.0);
        student2->addStudyResult("2", 8.7);

        student4->addStudyResult("1", 9.5);
        student4->addStudyResult("2", 7.7);

        student5->addStudyResult("1", 6.5);
        student5->addStudyResult("2", 8.7);

        itFaculty->addStudent(student1);
        itFaculty->addStudent(student3);
        itFaculty->addStudent(student5);

        businessFaculty->addStudent(student2);
        businessFaculty->addStudent(student4);
        

        listFaculties.push_back(itFaculty);
        listFaculties.push_back(businessFaculty);
    }

};
    
int main(){
    University university;
    university.addSampleData();
    int choice;
    while (1) {
        try {
            cout << "------- Menu -------" << endl;
            cout << "1. Add Student" << endl;
            cout << "2. Check Regular Student" << endl;
            cout << "3. Get Average Score of Semester" << endl;
            cout << "4. Display Total Regular Students" << endl;
            cout << "5. Find Student Highest Entry Score for each Faculties" << endl;
            cout << "6. Display Part-time Students of linked location for each Faculties" << endl;
            cout << "7. Get Students with Average Score >= 8.0 nearest for each Faculties" << endl;
            cout << "8. Get Student with Highest Average Score with semester for each Faculties" << endl;
            cout << "9. Sort Students by Type and Year Enrolled for each Faculties" << endl;
            cout << "10. Count Students by Year Enrolled for each Faculties" << endl;
            cout << "11. Display Students" << endl;
            cout << "0. Exit program" << endl;
            cout << "Your choice: ";
            
            cin >> choice;

            if (cin.fail()) {  
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                throw MenuException();
            }

            switch (choice) {
                case AddStudent: {
                    cout << "Enter Faculty Name: ";
                    string facultyName;
                    cin.ignore();
                    getline(cin, facultyName);
                    shared_ptr<Faculty> faculty = make_shared<Faculty>(facultyName);
                    university.addFaculty(faculty);
                    break;
                }
                
                case CheckRegularStudent: {
                    string id;
                    cout << "Enter Student ID: ";
                    cin >> id;
                    university.checkIsRegularById(id);
                    break;
                }

                case GetAverageScore: {
                    string id, semester;
                    cout << "Enter Student ID: ";
                    cin >> id;
                    cout << "Enter Semester: ";
                    cin >> semester;

                    university.getAverageScoreById(id, semester);
                    break;
                }

                case DisplayTotalRegularStudents: {
                    university.displayTotalRegularStudents();
                    break;
                }

                case FindStudentHighestEntryScore: {
                    university.findStudentHighestEntryScore();
                    break;
                }

                case ListPartTimeStudentsByLocation: {
                    string location;
                    cout << "Enter Location: ";
                    cin.ignore();
                    getline(cin, location);
                    university.listPartTimeStudentsByLocation(location);
                    break;
                }

                case ListStudentsAbove8InLatestSemester: {
                    university.listStudentsAbove8InLatestSemester();
                    break;
                }

                case FindStudentHighestSemesterScore: {
                    university.findStudentHighestSemesterScore();
                    break;
                }

                case SortStudentsByTypeAndYear: {
                    university.sortStudentsByTypeAndYear();
                    break;
                }

                case CountStudentsByYear: {
                    university.countStudentsByYear();
                    break;
                }

                case DisplayStudents: {
                    university.displayFaculties();
                    break;
                }

                case Exit:
                    cout << "Exiting program..." << endl;
                    return 0;
                default:
                    throw MenuException();
            }
        } catch (const MenuException& e) {
            cerr << "Error: " << e.what() << endl;
        } catch (const exception& e) {
            cerr << "Unexpected Error: " << e.what() << endl;
        }
    }
    return 0;
}
