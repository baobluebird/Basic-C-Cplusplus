// Yêu cầu 3: Chương trình cần có chức năng lựa chọn ứng viên trúng tuyển vào công ty theo nguyên tắc sau:

// Người dùng sẽ nhập vào số lượng sinh viên cần tuyển dụng (tối thiểu là 11, tối đa là 15).
// Chương trình sẽ tự động chọn ra ứng viên phù hợp cho công ty theo các bước như sau:
// Nếu số lượng ứng viên là sinh viên khá giỏi có nhiều hơn số lượng cần tuyển thì xét ưu tiên theo điểm GPA. Nếu xuất hiện ứng viên khá giỏi có cùng điểm GPA thì xét ưu tiên theo họ tên. Vd: nếu họ tên là Nguyễn Văn A và Nguyễn Văn B thì ứng viên Nguyễn Văn A được chọn. (Giả sử không bao giờ có sinh viên có trùng họ tên nhau).
// Nếu số lượng ứng viên là sinh viên khá giỏi ít hơn hoặc bằng số lượng cần tuyển thì nhận hết sinh viên khá giỏi.
// Sau khi tuyển hết ứng viên khá giỏi, nếu vẫn chưa đủ số lượng cần tuyển, chương trình sẽ lấy ứng viên trung bình. Các ứng viên trung bình được xét ưu tiên theo điểm thi đầu vào, nếu điểm thi đầu vào bằng nhau thì xét đến điểm TOEIC. Nếu xuất hiện ứng viên trung bình có cùng điểm TOEIC thì xét ưu tiên theo họ tên.
// Yêu cầu 4: Chương trình có thể hiển thị được thông tin họ tên và số điện thoại của tất cả các sinh viên đã nhập vào hệ thống (yêu cầu dùng collection sort để sắp xếp giảm dần theo fullName và tăng dần theo phoneNumber đối với sinh viên trước khi hiển thị).
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <regex>
#include <memory>
#include <iomanip>
#include <limits>
#include <fstream>
#include <sstream>

using namespace std;

class InvalidFullNameException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid name. Name must not contain numbers or special characters (Minimum 3 characters)!";
    }
};
class InvalidDOBException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid date format!";
    }
};

class InvalidPhoneNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid phone number! Must be starts with 0 and contains no characters";
    }
};

bool isValidDOB(const string& birthday) {
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

bool isValidPhone(const string& phone) {
    regex pattern(R"(^0\d{9}$)"); 
    return regex_match(phone, pattern);
}

bool isValidFullName(const string& fullName) {
    regex pattern(R"(^[A-Za-zÀ-ỹ ]{3,}$)");
    return regex_match(fullName, pattern);
}

class Student {
private:
    string fullName, doB, sex, phoneNumber, universityName, gradeLevel;

public:
    Student() : fullName(""), doB(""), sex(""), phoneNumber(""), universityName(""), gradeLevel("") {}
    Student(string fullName, string doB, string sex, string phoneNumber, string universityName, string gradeLevel){
        if (!isValidFullName(fullName)) {
            throw InvalidFullNameException();
        }
        if (!isValidDOB(doB)) {
            throw InvalidDOBException();
        }
        if (!isValidPhone(phoneNumber)) {
            throw InvalidPhoneNumberException();
        }
        this->fullName = fullName;
        this->doB = doB;
        this->sex = sex;
        this->phoneNumber = phoneNumber;
        this->universityName = universityName;
        this->gradeLevel = gradeLevel;
    }
    
    string getFullName(){ 
        return this->fullName; 
    }

    string getPhoneNumber(){ 
        return this->phoneNumber; 
    }

    virtual float getGPA() {
        return 0.0f;
    }

    virtual int getEnglishScore() {
        return 0;
    }

    virtual float getEntryTestScore() {
        return 0.0f;
    }

    virtual void ShowMyInfor(){
            cout << left << setw(20) << this->fullName
         << setw(15) << this->doB
         << setw(10) << this->sex
         << setw(15) << this->phoneNumber
         << setw(20) << this->universityName
         << setw(10) << this->gradeLevel;
    }
    virtual string getType()  = 0;
    virtual ~Student() {}
};

class GoodStudent : public Student {
private:
    float gpa;
    string bestRewardName;
public:
    GoodStudent() : gpa(0.0f), bestRewardName("") {}
    GoodStudent(string fullName, string doB, string sex, string phoneNumber, string universityName, string gradeLevel, float gpa, string bestRewardName)
        : Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), gpa(gpa), bestRewardName(bestRewardName) {}

    void ShowMyInfor() override {
        cout << left << setw(15) << "Good Student";
        Student::ShowMyInfor();
        cout << setw(10) << this->gpa
             << setw(20) << this->bestRewardName << endl;
    }

    float getGPA() override {
        return this->gpa; 
    }

    int getEnglishScore() override {
        return 0;
    }

    float getEntryTestScore() override {
        return 0.0f;
    }

    string getType() override {
        return "Good Student";
    }

};

class NormalStudent : public Student {
private:
    int englishScore;
    float entryTestScore;
public:
    NormalStudent() : englishScore(0), entryTestScore(0.0f) {}
    NormalStudent(string fullName, string doB, string sex, string phoneNumber, string universityName, string gradeLevel, int englishScore, float entryTestScore)
        : Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), englishScore(englishScore), entryTestScore(entryTestScore) {}

    void ShowMyInfor() override{
        cout << left << setw(15) << "Normal Student";
        Student::ShowMyInfor();
        cout << setw(10) << englishScore
             << setw(10) << entryTestScore << endl;
    }

    int getEnglishScore() override {
        return this->englishScore;
    }

    float getEntryTestScore() override {
        return this->entryTestScore;
    }

    float getGPA() override {
        return 0.0f;
    }

    string getType() override {
        return "Normal Student";
    }

};

class StudentManager {
private:    
    vector<shared_ptr<Student>> listStudents;

public:
    void addStudent(shared_ptr<Student> student) {
        listStudents.push_back(student);
    }

    void readFromFile(const string& filename, string isGoodStudent) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Cannot open file " << filename << endl;
            exit(EXIT_FAILURE);
        }

        string line;
        int numLine = 0;

        try {
            while (getline(file, line)) {
                numLine++;
                
                stringstream ss(line);
                vector<string> fields;
                string field;

                while (getline(ss, field, ',')) {
                    fields.push_back(field);
                }

                if ((isGoodStudent == "Good Student" && fields.size() != 8) || 
                    (isGoodStudent == "Normal Student" && fields.size() != 8)) {
                    cerr << "Invalid CSV format in line " << numLine << ": " << line << endl;
                    throw runtime_error("Invalid CSV format or missing fields.");
                }

                string fullName = fields[0];
                string doB = fields[1];
                string sex = fields[2];
                string phoneNumber = fields[3];
                string universityName = fields[4];
                string gradeLevel = fields[5];

                if (!isValidFullName(fullName)) {
                    throw InvalidFullNameException();
                }
                if (!isValidDOB(doB)) {
                    throw InvalidDOBException();
                }
                if (!isValidPhone(phoneNumber)) {
                    throw InvalidPhoneNumberException();
                }

                if (isGoodStudent == "Good Student") {
                    float gpa = stof(fields[6]);
                    string bestRewardName = fields[7];

                    shared_ptr<Student> student = make_shared<GoodStudent>(
                        fullName, doB, sex, phoneNumber, universityName, gradeLevel, gpa, bestRewardName);

                    addStudent(student);
                } else {
                    int englishScore = stof(fields[6]);
                    float entryTestScore = stof(fields[7]);

                    shared_ptr<Student> student = make_shared<NormalStudent>(
                        fullName, doB, sex, phoneNumber, universityName, gradeLevel, englishScore, entryTestScore);

                    addStudent(student);
                }
            }
        } catch (const InvalidFullNameException& e) {
            cerr << "Critical error in file '" << filename << "' at line " << numLine << ": " << line << endl;
            cerr << e.what() << endl;
            exit(EXIT_FAILURE);
        } catch (const InvalidDOBException& e) {
            cerr << "Critical error in file '" << filename << "' at line " << numLine << ": " << line << endl;
            cerr << e.what() << endl;
            exit(EXIT_FAILURE);
        } catch (const InvalidPhoneNumberException& e) {
            cerr << "Critical error in file '" << filename << "' at line " << numLine << ": " << line << endl;
            cerr << e.what() << endl;
            exit(EXIT_FAILURE);
        } catch (const exception& e) {
            cerr << "Input files have unknown errors !!!" << endl;
            cerr << "Error in line " << numLine << ": " << line << endl;
            exit(EXIT_FAILURE);
        }
    }

    void displayRecruitedStudents(int n) {
        vector<shared_ptr<Student>> goodStudents;
        vector<shared_ptr<Student>> normalStudents;

        for (shared_ptr<Student> student : listStudents) {
            if (student->getType() == "Good Student") {
                goodStudents.push_back(student);
            } else {
                normalStudents.push_back(student);
            }
        }

        sort(goodStudents.begin(), goodStudents.end(), [](shared_ptr<Student> a, shared_ptr<Student> b) {
            if (a->getGPA() != b->getGPA()) {
                return a->getGPA() > b->getGPA();
            }
            return a->getFullName() < b->getFullName();
        });

        sort(normalStudents.begin(), normalStudents.end(), [](shared_ptr<Student> a, shared_ptr<Student> b) {
            if (a->getEntryTestScore() != b->getEntryTestScore()) {
                return a->getEntryTestScore() > b->getEntryTestScore();
            }

            if(a->getEnglishScore() != b->getEnglishScore()) {
                return a->getEnglishScore() > b->getEnglishScore();
            }

            return a->getFullName() < b->getFullName();
        });

        vector<shared_ptr<Student>> recruitedStudents;

        int goodCount = goodStudents.size();
        int recruited = 0;

        for (size_t i = 0; i < goodCount && recruited < n; ++i) {
            recruitedStudents.push_back(goodStudents[i]);
            ++recruited;
        }

        for (size_t i = 0; i < normalStudents.size() && recruited < n; ++i) {
            recruitedStudents.push_back(normalStudents[i]);
            ++recruited;
        }

        cout << "--- Recruited Students ---" << endl;
        for (shared_ptr<Student> s : recruitedStudents) {
            s->ShowMyInfor();
        }
    }

    void displayAllStudents() {
        sort(listStudents.begin(), listStudents.end(), [](shared_ptr<Student> a, shared_ptr<Student> b) {
            if (a->getFullName() != b->getFullName()) {
                return a->getFullName() < b->getFullName();
            }
            return a->getPhoneNumber() < b->getPhoneNumber();
        });
        cout << left << setw(15) << "Type"
                     << setw(20) << "Full Name"
                     << setw(15) << "Birthday"
                     << setw(10) << "Sex"
                     << setw(15) << "Phone"
                     << setw(20) << "University"
                     << setw(10) << "Grade"
                     << setw(10) << "GPA/TOEIC"
                     << setw(10) << "BestRewardName/EntryTest" << endl;
        cout << string(125, '-') << endl;
        for (shared_ptr<Student> s : listStudents) {
            s->ShowMyInfor();
        }
    }
};

int main() {
    StudentManager manager;
    manager.readFromFile("good_student.csv", "Good Student");
    manager.readFromFile("normal_student.csv", "Normal Student");
    manager.displayAllStudents();
    cout << "Number of students to recruit (minimum 11, maximum 15 or enter 0 to exit): ";
    int n; 
    while(true) {
        cin >> n;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if(n == 0) {
            return 0;
        }
        if (n >= 11 && n <= 15) {
            break;
        }
        cout << "Invalid number of students to recruit. Please enter again: ";
    }
    
    manager.displayRecruitedStudents(n);


    return 0;
}