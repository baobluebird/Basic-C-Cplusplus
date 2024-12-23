#include <iostream>

class MyClass {
public:
    int* data;

    // Constructor
    MyClass(int value) : data(new int(value)) {}

    // Copy Constructor (Shallow Copy)
    MyClass(const MyClass& other) : data(other.data) {}

    ~MyClass() {
        delete data; // Giải phóng tài nguyên
        std::cout << "Destructor called.\n";
    }
};

int main() {
    MyClass obj1(10);
    MyClass obj2 = obj1; // Shallow Copy

    // Cả obj1 và obj2 dùng chung một vùng nhớ
    delete obj1.data; // Khi hủy obj1, obj2 sẽ trỏ vào vùng nhớ không hợp lệ
    return 0;
}
