#include "university.h"

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