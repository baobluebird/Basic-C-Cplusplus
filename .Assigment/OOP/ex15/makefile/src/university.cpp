#include "university.h"
#include "regular_student.h"
#include "part_time_student.h"

void University::addFaculty(shared_ptr<Faculty> faculty){
    faculty->addStudentByType();
    listFaculties.push_back(faculty);
}

void University::displayFaculties(){
    for (shared_ptr<Faculty> faculty : listFaculties)
    {
        cout << "Faculty: " << faculty->getFacultyName() << endl;
        faculty->displayStudents();
    }
}

void University::checkIsRegularById(string id){
    for (shared_ptr<Faculty> faculty : listFaculties)
    {
        faculty->checkIsRegularById(id);
    }
}

float University::getAverageScoreById(string id, string semester){
    bool studentFound = false;

    for (shared_ptr<Faculty> faculty : listFaculties)
    {
        float avg = faculty->getAverageScoreById(id, semester);
        if (avg != -2)
        {
            studentFound = true;
            return avg;
        }
    }

    if (!studentFound)
    {
        cout << "Student with ID " << id << " not found in any faculty." << endl;
    }
    return -1;
}

void University::displayTotalRegularStudents(){
    int count = 0;
    for (shared_ptr<Faculty> faculty : listFaculties)
    {
        count += faculty->displayTotalRegularStudents();
    }
    cout << "Total Regular Students: " << count << endl;
}

void University::findStudentHighestEntryScore(){
    float maxScore = 0.0;
    for (shared_ptr<Faculty> faculty : listFaculties)
    {
        maxScore = max(maxScore, faculty->findStudentHighestEntryScore());
    }
    cout << "Highest Entry Score: " << maxScore << endl;
}

void University::listPartTimeStudentsByLocation(string location){
    for (shared_ptr<Faculty> faculty : listFaculties)
    {
        faculty->listPartTimeStudentsByLocation(location);
    }
}

void University::listStudentsAbove8InLatestSemester(){
    for (shared_ptr<Faculty> faculty : listFaculties)
    {
        faculty->listStudentsAbove8InLatestSemester();
    }
}

void University::findStudentHighestSemesterScore(){
    for (auto &faculty : listFaculties)
    {
        faculty->findStudentHighestSemesterScore();
    }
}

void University::sortStudentsByTypeAndYear(){
    for (auto &faculty : listFaculties)
    {
        faculty->sortStudentsByTypeAndYear();
    }
}

void University::countStudentsByYear(){
    for (auto &faculty : listFaculties)
    {
        faculty->countStudentsByYear();
    }
}

void University::addSampleData(){
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
