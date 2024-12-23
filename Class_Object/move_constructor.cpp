#include <iostream>
#include <string>

class MyClass {
public:
    std::string name;

    // Constructor thông thường
    MyClass(const std::string& name) : name(name) {}

    // Move Constructor
    MyClass(MyClass&& other) noexcept : name(std::move(other.name)) {
        std::cout << "Move Constructor called.\n";
    }
};

int main() {
    MyClass obj1("Object1");
    MyClass obj2 = std::move(obj1); // Gọi Move Constructor
    std::cout << "obj2 name: " << obj2.name << "\n";
    
    std::cout << "obj1_old name: " << obj1.name << "\n";

    int a;
    std::cout << "a" << a;
    return 0;
}
