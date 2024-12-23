#include <iostream>
using namespace std;

class MyClass
{
public:
    // Constructor has one parameter
    MyClass(int x)
    {
        cout << "Constructor called with value: " << x << endl;
    }
};

void print(MyClass obj)
{
    cout << "print() function called" << endl;
}

int main()
{
    print(10); // Potential error: Calling default constructor MyClass(10)
    return 0;
}

// #include <iostream>
// using namespace std;

// class MyClass
// {
// public:
//     // Constructor used explicitly
//     explicit MyClass(int x)
//     {
//         cout << "Constructor called with value: " << x << endl;
//     }
// };

// void print(MyClass obj)
// {
//     cout << "print() function called" << endl;
// }

// int main()
// {
//     // print(10); // Compile error: Implicit initialization not possible
//     print(MyClass(10)); // OK: Must be called explicitly
//     return 0;
// }