#include "study_result.h"

bool StudyResult::isValidString(const string& str) {
    return !str.empty() && regex_match(str, regex("^[A-Za-zÀ-ỹ\\s]+$"));
}

bool StudyResult::isValidScore(const float& score) {
    return (score >= 0.0f && score <= 10.0f);
}

StudyResult::StudyResult() : Semester(""), avgScore(0.0) {}

StudyResult::StudyResult(string Semester, float avgScore)
    : Semester(Semester), avgScore(avgScore) {}

string StudyResult::getSemesterName(){
    return this->Semester;
}

float StudyResult::getAvgScore(){
    return this->avgScore;
}

void StudyResult::inputSemester(){
    cout << "Enter Semester: ";
    cin >> this->Semester;
}

void StudyResult::inputAvgScore(){
    while (true){
        try{
            cout << "Enter Average Score: ";
            cin >> this->avgScore;

            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw MustBeNumberException();
            }

            if (!isValidScore(this->avgScore)){
                throw ScoreException();
            }
            break;
        }
        catch (const MustBeNumberException &e){
            cerr << "Error: " << e.what() << endl;
        }
        catch (const ScoreException &e){
            cerr << "Error: " << e.what() << endl;
        }
    }
}

void StudyResult::addStudyResult(){
    inputSemester();
    inputAvgScore();
}

void StudyResult::displayStudyResult(){
    cout << "Semester: " << this->Semester << ", Average Score: " << this->avgScore << endl;
}