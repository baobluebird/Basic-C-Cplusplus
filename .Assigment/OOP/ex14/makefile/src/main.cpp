#include "student_manager.h"

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