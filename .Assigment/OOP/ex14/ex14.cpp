#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <regex>
#include <memory>
#include <fstream>
#include <sstream>
#define AddStudent 1

using namespace std;

class InvalidFullNameException : public exception {
    const char* what() const noexcept override {
        return "Invalid Full Name! Must be between 10 and 50 characters.";
    }
};

class InvalidDOBException : public exception {
    const char* what() const noexcept override {
        return "Invalid Date of Birth format! Must be dd/MM/yyyy.";
    }
};

class InvalidPhoneNumberException : public exception {
    const char* what() const noexcept override {
        return "Invalid Phone Number! Must start with 090, 098, 091, 031, 035, or 038.";
    }
};

class Student {
protected:
    string fullName, doB, sex, phoneNumber, universityName, gradeLevel;
public:
    Student(string fullName, string doB, string sex, string phoneNumber, string universityName, string gradeLevel){
        if (!isValidFullName(fullName)) {
            throw InvalidFullNameException();
        }
        if (!isValidDOB(doB)) {
            throw InvalidDOBException();
        }
        if (!isValidPhoneNumber(phoneNumber)) {
            throw InvalidPhoneNumberException();
        }
        this->fullName = fullName;
        this->doB = doB;
        this->sex = sex;
        this->phoneNumber = phoneNumber;
        this->universityName = universityName;
        this->gradeLevel = gradeLevel;
    }
    
    string getFullName() const { 
        return this->fullName; 
    }
    string getPhoneNumber() const { 
        return this->phoneNumber; 
    }

    static bool isValidFullName(const string& name) {
        return name.length() >= 10 && name.length() <= 50;
    }

    static bool isValidDOB(const string& dob) {
        regex dobPattern("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[012])/\\d{4}$");
        return regex_match(dob, dobPattern);
    }

    static bool isValidPhoneNumber(const string& phone) {
        regex phonePattern("^(090|098|091|031|035|038)\\d{7}$");
        return regex_match(phone, phonePattern);
    }

    virtual float getPriorityScore() const = 0;
    virtual void ShowMyInfor() const = 0;
    virtual ~Student() {}
};

class GoodStudent : public Student {
    float gpa;
    string bestRewardName;
public:
    GoodStudent(string fullName, string doB, string sex, string phoneNumber, string universityName, string gradeLevel, float gpa, string bestRewardName)
        : Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), gpa(gpa), bestRewardName(bestRewardName) {}

    void ShowMyInfor() const override {
        cout << "Good Student: " << this->fullName << " - Phone: " << this->phoneNumber << " - GPA: " << this->gpa << " - Reward: " << this->bestRewardName << endl;
    }

    float getPriorityScore() const override {
        return this->gpa;
    }
};

class NormalStudent : public Student {
    float englishScore, entryTestScore;
public:
    NormalStudent(string fullName, string doB, string sex, string phoneNumber, string universityName, string gradeLevel, float englishScore, float entryTestScore)
        : Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), englishScore(englishScore), entryTestScore(entryTestScore) {}

    void ShowMyInfor() const override {
        cout << "Normal Student: " << this->fullName << " - Phone: " << this->phoneNumber << " - Entry Test: " << this->entryTestScore << " - TOEIC: " << this->englishScore << endl;
    }

    float getPriorityScore() const override {
        return this->entryTestScore * 10 + this->englishScore;
    }
};

class StudentManager {
    vector<shared_ptr<Student>> students;
    
    void SortByNameAndPhone() {
        for (size_t i = 0; i < students.size() - 1; i++) {
            for (size_t j = i + 1; j < students.size(); j++) {
                if (students[i]->getFullName() < students[j]->getFullName() || 
                   (students[i]->getFullName() == students[j]->getFullName() && 
                    students[i]->getPhoneNumber() > students[j]->getPhoneNumber())) {
                    swap(students[i], students[j]);
                }
            }
        }
    }
public:
    void addStudent(shared_ptr<Student> student) {
        students.push_back(student);
    }

    void readFromFile(const string& filename, string isGoodStudent) {
        ifstream file(filename);
        string line;

        regex dobPattern(R"(\d{2}/\d{2}/\d{4})");

        while (getline(file, line)) {
            smatch match;
            if (regex_search(line, match, dobPattern)) {
                string fullName = line.substr(0, match.position() - 1);
                stringstream ss(line.substr(match.position()));

                string doB, sex, phoneNumber, universityName, gradeLevel, bestRewardName;
                float gpa, entryTestScore, englishScore;

                ss >> doB >> sex >> phoneNumber >> universityName >> gradeLevel;

                try {
                    if (isGoodStudent == "Good") {
                        ss >> gpa >> bestRewardName;
                        addStudent(make_shared<GoodStudent>(fullName, doB, sex, phoneNumber, universityName, gradeLevel, gpa, bestRewardName));
                    } else {
                        ss >> englishScore >> entryTestScore;
                        addStudent(make_shared<NormalStudent>(fullName, doB, sex, phoneNumber, universityName, gradeLevel, englishScore, entryTestScore));
                    }
                } catch (const exception& e) {
                    cerr << "Error adding student from line: " << line << endl;
                    cerr << e.what() << endl;
                }
            } else {
                cerr << "Invalid format in file: " << line << endl;
            }
        }
    }

    void displayAllStudents() {
        SortByNameAndPhone();
        for (auto& s : students) {
            cout << s->getFullName() << " - Phone: " << s->getPhoneNumber() << endl;
        }
    }
};

int main() {
    StudentManager manager;
    manager.readFromFile("good_student.inp", "Good");
    manager.readFromFile("normal_student.inp", "Normal");
    manager.displayAllStudents();
    return 0;
}