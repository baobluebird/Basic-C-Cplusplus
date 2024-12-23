#include <iostream>
#include <memory> // Library for smart pointer

class MyClass
{
public:
    MyClass(int a, double b, const std::string &c)
        : attribute1(a), attribute2(b), attribute3(c)
    {
        std::cout << "Object created with attributes: "
                  << attribute1 << ", " << attribute2 << ", " << attribute3 << std::endl;
    }

    ~MyClass()
    {
        std::cout << "Object is destroyed." << std::endl;
    }

    void showAttributes() const
    {
        std::cout << "Attributes: "
                  << attribute1 << ", "
                  << attribute2 << ", "
                  << attribute3 << std::endl;
    }

    void setAttributes(int a, double b, const std::string &c)
    {
        attribute1 = a;
        attribute2 = b;
        attribute3 = c;
    }

private:
    int attribute1;
    double attribute2;
    std::string attribute3;
};

int main()
{
    // Use unique_ptr to manage MyClass objects with many properties
    std::unique_ptr<MyClass> uniquePtr = std::make_unique<MyClass>(42, 3.14, "Hello, World");

    // Access and show object attributes
    uniquePtr->showAttributes();

    std::unique_ptr<MyClass> uniquePtr2 = std::move(uniquePtr);

    uniquePtr2->setAttributes(100, 2.718, "Goodbye, World");

    uniquePtr2->showAttributes();

    uniquePtr->showAttributes();
    
    // uniquePtr automatically destroys the object when it goes out of scope
    return 0;
}