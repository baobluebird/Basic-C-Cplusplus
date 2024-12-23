#include <iostream>
using namespace std;

class MyClass
{
private:
    int a;

public:
    int b;

    MyClass(int val) : a(val) {}

    void setA(int val)
    {
        // Use the 'this' pointer to access the current object's member 'a'
        this->a = val;
    }

    void display() const
    {
        // Use the 'this' pointer to access the 'a' member
        cout << "Value of a: " << this->a << endl;
    }

    // This function will return the address of the current object
    MyClass *getThis()
    {
        return this; // Return the 'this' pointer
    }
};

int main()
{
    MyClass obj(10);
    MyClass obj2(10);
    obj.display(); // Output: Value of a: 10

    obj.setA(20);
    obj.display(); // Output: Value of a: 20

    // Return the 'this' pointer and use it
    MyClass *ptr = obj.getThis();
    cout << "Address of obj: " << ptr << endl;

    MyClass *ptr2 = obj2.getThis();
    cout << "Address of obj2: " << ptr2 << endl;

    ptr->setA(30);
    ptr->display(); // Output: Value of a: 30

    //ptr->a = 40; // Error: 'a' is a private member of MyClass
    ptr2->b = 40;
    cout << "Value of b: " << ptr2->b << endl; // Output: Value of b: 40

    return 0;
}   