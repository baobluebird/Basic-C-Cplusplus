#include "student_manager.h"
#include "good_student.h"
#include "normal_student.h"

void StudentManager::addStudent(shared_ptr<Student> student){
    students.push_back(student);
}

void StudentManager::readFromFile(const string &filename, string isGoodStudent){
    ifstream file(filename);
    if (!file){
        cerr << "Error: Cannot open file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    int numLine = 0;

    try{
        while (getline(file, line)){
            numLine++;

            stringstream ss(line);
            vector<string> fields;
            string field;

            while (getline(ss, field, ',')){
                fields.push_back(field);
            }

            if ((isGoodStudent == "Good Student" && fields.size() != 8) ||
                (isGoodStudent == "Normal Student" && fields.size() != 8)){
                cerr << "Invalid CSV format in line " << numLine << ": " << line << endl;
                throw runtime_error("Invalid CSV format or missing fields.");
            }

            string fullName = fields[0];
            string doB = fields[1];
            string sex = fields[2];
            string phoneNumber = fields[3];
            string universityName = fields[4];
            string gradeLevel = fields[5];

            if (!isValidFullName(fullName)){
                throw InvalidFullNameException();
            }
            if (!isValidDOB(doB)){
                throw InvalidDOBException();
            }
            if (!isValidPhone(phoneNumber)){
                throw InvalidPhoneNumberException();
            }

            if (isGoodStudent == "Good Student"){
                float gpa = stof(fields[6]);
                string bestRewardName = fields[7];

                shared_ptr<Student> student = make_shared<GoodStudent>(
                    fullName, doB, sex, phoneNumber, universityName, gradeLevel, gpa, bestRewardName);

                addStudent(student);
            }else{
                int englishScore = stof(fields[6]);
                float entryTestScore = stof(fields[7]);

                shared_ptr<Student> student = make_shared<NormalStudent>(
                    fullName, doB, sex, phoneNumber, universityName, gradeLevel, englishScore, entryTestScore);

                addStudent(student);
            }
        }
    }
    catch (const InvalidFullNameException &e){
        cerr << "Critical error in file '" << filename << "' at line " << numLine << ": " << line << endl;
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }
    catch (const InvalidDOBException &e){
        cerr << "Critical error in file '" << filename << "' at line " << numLine << ": " << line << endl;
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }
    catch (const InvalidPhoneNumberException &e){
        cerr << "Critical error in file '" << filename << "' at line " << numLine << ": " << line << endl;
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }
    catch (const exception &e){
        cerr << "Input files have unknown errors !!!" << endl;
        cerr << "Error in line " << numLine << ": " << line << endl;
        exit(EXIT_FAILURE);
    }
}

void StudentManager::displayRecruitedStudents(int n){
    vector<shared_ptr<Student>> goodStudents;
    vector<shared_ptr<Student>> normalStudents;

    for (shared_ptr<Student> student : students){
        if (student->getType() == "Good Student")
        {
            goodStudents.push_back(student);
        }else{
            normalStudents.push_back(student);
        }
    }

    sort(goodStudents.begin(), goodStudents.end(), [](shared_ptr<Student> a, shared_ptr<Student> b){
            if (a->getGPA() != b->getGPA()) {
                return a->getGPA() > b->getGPA();
            }
            return a->getFullName() < b->getFullName(); });

    sort(normalStudents.begin(), normalStudents.end(), [](shared_ptr<Student> a, shared_ptr<Student> b){
            if (a->getEntryTestScore() != b->getEntryTestScore()) {
                return a->getEntryTestScore() > b->getEntryTestScore();
            }

            if(a->getEnglishScore() != b->getEnglishScore()) {
                return a->getEnglishScore() > b->getEnglishScore();
            }

            return a->getFullName() < b->getFullName(); });

    vector<shared_ptr<Student>> recruitedStudents;

    size_t goodCount = goodStudents.size();
    int recruited = 0;

    for (size_t i = 0; i < goodCount && recruited < n; ++i){
        recruitedStudents.push_back(goodStudents[i]);
        ++recruited;
    }

    for (size_t i = 0; i < normalStudents.size() && recruited < n; ++i){
        recruitedStudents.push_back(normalStudents[i]);
        ++recruited;
    }

    cout << "--- Recruited Students ---" << endl;
    for (shared_ptr<Student> s : recruitedStudents){
        s->ShowMyInfor();
    }
}

void StudentManager::displayAllStudents(){
    sort(students.begin(), students.end(), [](shared_ptr<Student> a, shared_ptr<Student> b){
            if (a->getFullName() != b->getFullName()) {
                return a->getFullName() < b->getFullName();
            }
            return a->getPhoneNumber() < b->getPhoneNumber(); });
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
    for (shared_ptr<Student> s : students){
        s->ShowMyInfor();
    }
}