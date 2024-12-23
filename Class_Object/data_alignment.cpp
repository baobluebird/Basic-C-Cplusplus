#include <iostream>
using namespace std;

class MyClass {
public:
    char a;     // 1 byte
    double b;   // 8 bytes
    int c;      // 4 bytes
};

int main() {
    cout << "Size of MyClass: " << sizeof(MyClass) << " bytes" << endl;
    return 0;
}

// #include <iostream>
// using namespace std;

// class MyClass {
// public:
//     double b;   // 8 bytes
//     int c;      // 4 bytes
//     char a;     // 1 byte
// };

// int main() {
//     cout << "Size of MyClass: " << sizeof(MyClass) << " bytes" << endl;
//     return 0;
// }

