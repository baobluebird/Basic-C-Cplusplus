// #include <iostream>
// using namespace std;

// class MyClass {
// public:
//     static void display() {
//         cout << "Static member function called." << endl;
//     }
// };

// int main() {
//     MyClass::display();  // Call static method without creating object
//     return 0;
// }

#include <iostream>
using namespace std;

class MyClass {
public:
    static int staticData; // Declare static properties
    void display() {
        cout << "Static data: " << staticData << endl;
    }
};

// Initialize static properties outside the class
int MyClass::staticData = 5; // Initialize static properties

int main() {
    MyClass obj1, obj2;

    obj1.display(); // Static data: 5
    obj2.display(); // Static data: 5

    // Change static property value
    MyClass::staticData = 10;

    obj1.display(); // Static data: 10
    obj2.display(); // Static data: 10

    return 0;
}