#include "student_university.h"

set<string> Student::usedStudentIDs;

bool Student::isValidDate(const string &birthday){
    regex pattern(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\d{4}$)");
    if (!regex_match(birthday, pattern))
        return false;

    int day, month, year;
    sscanf(birthday.c_str(), "%d/%d/%d", &day, &month, &year);

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        daysInMonth[2] = 29;
    }

    return day <= daysInMonth[month];
}

bool Student::isValidFullName(const string &fullName){
    regex pattern(R"(^[A-Za-zÀ-ỹ ]{3,}$)");
    return regex_match(fullName, pattern);
}

bool Student::isValidYear(const string &year){
    regex yearPattern(R"(^(19[0-9]{2}|20[0-9]{2})$)");
    return regex_match(year, yearPattern);
}

bool Student::isValidScore(const float &score){
    return (score >= 0.0f && score <= 10.0f);
}

bool Student::isValidString(const string &str){
    return !str.empty() && regex_match(str, regex("^[A-Za-zÀ-ỹ\\s]+$"));
}

Student::Student() : studentID(""), fullName(""), dob(""), yearEnrolled(0), entryScore(0.0) {}

Student::Student(string studentID, string fullName, string dob, int yearEnrolled, float entryScore)
    : studentID(studentID), fullName(fullName), dob(dob), yearEnrolled(yearEnrolled), entryScore(entryScore) {
        usedStudentIDs.insert(studentID);
    }

string Student::getStudentID(){
    return this->studentID; 
}

int Student::getYearEnrolled(){ 
    return this->yearEnrolled; 
}

float Student::getEntryScore(){ 
    return this->entryScore; 
}
    
string Student::getFullName(){ 
    return this->fullName; 
}

float Student::getAverageScore(string semester){
    for (StudyResult& studyResult : studyResults){
        if (studyResult.getSemesterName() == semester){
            return studyResult.getAvgScore();
        }
    }
    cout << "No results found for semester: " << semester << endl;
    return -1; 
}

void Student::inputName(){
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

void Student::inputBirthday(){
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

void Student::inputYearEnrolled() {
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

void Student::inputEntryScore(){
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

void Student::addStudyResult(string semester, float avgScore) {
    StudyResult newResult(semester, avgScore);
    studyResults.push_back(newResult);
}

void Student::displayStudyResults(){
    cout << string(60, '*') << endl;
    cout << "Study Results: " << this->fullName << endl;
    for (StudyResult& studyResult : studyResults){
        studyResult.displayStudyResult();
    }
    cout << string(60, '*') << endl;
}

float Student::getLatestSemesterScoreAbove8() {
    if (studyResults.empty()) {
        return -1;
    }
        
    auto& latestResult = studyResults[studyResults.size() - 1];

    if (latestResult.getAvgScore() >= 8.0) {
        return latestResult.getAvgScore();
    }

    return -1;
}

float Student::getHighestSemesterScore() {
    float highestScore = 0.0;
    for (StudyResult& studyResult : studyResults) {
        if (studyResult.getAvgScore() > highestScore) {
            highestScore = studyResult.getAvgScore();
        }
    }
    return highestScore;
}

void Student::inputStudent(){
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

void Student::displayStudent() {
    cout << left << setw(10) << studentID
        << setw(25) << fullName
        << setw(15) << dob
        << setw(10) << yearEnrolled
        << setw(10) << entryScore << endl;
}

string Student::getLinkedLocation() {
    return ""; 
}
