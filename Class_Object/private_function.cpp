#include <iostream>
using namespace std;

class MyClass {
private:
    void privateFunction() {
        cout << "This is a private function." << endl;
    }

public:
    void publicFunction() {
        privateFunction(); // Call private function from inside class
    }
};

int main() {
    MyClass obj;
    obj.publicFunction(); // Call public method from object
    // obj.privateFunction(); // Error: Cannot call private function from outside
    return 0;
}
