#include <iostream>  // Make sure to include this header

using namespace std;

int main() {
    #ifdef _WIN32
        cout << "Chạy trên Windows\n";  // Windows specific message
    #else
        cout << "Chạy trên hệ điều hành khác\n";  // Non-Windows specific message
    #endif

    return 0;
}

//run code
/*

g++ check_os.cpp -o program
.\program.exe

*/
