#include <iostream>

class MyClass {
private:
    int y;
public:
    int* data;
    int x;
    // Constructor
    MyClass(int value) : data(new int(value)) {}

    // Copy Constructor (Deep Copy)
    MyClass(const MyClass& other) : data(new int(*other.data)) {}

    ~MyClass() {
        delete data; // Giải phóng tài nguyên
        std::cout << "Destructor called.\n";
    }
};

int main() {
    MyClass obj1(10);
    MyClass obj2 = obj1; // Deep Copy

    *obj2.data = 20; // Thay đổi dữ liệu của obj2, không ảnh hưởng đến obj1
    

    std::cout << "obj1 data: " << *obj1.data << "\n";
    std::cout << "obj2 data: " << *obj2.data << "\n";
    return 0;
}
