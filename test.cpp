#include <iostream>
using namespace std;

// Lớp interface
class Shape {
public:
    virtual void draw() const = 0; // Hàm thuần ảo
    virtual double calculateArea() const = 0; // Hàm thuần ảo

    // Virtual destructor để hỗ trợ kế thừa
    virtual ~Shape() {}
};

// Lớp dẫn xuất cụ thể
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() const override {
        cout << "Drawing Circle with radius: " << radius << endl;
    }

    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
};

// Lớp dẫn xuất cụ thể khác
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void draw() const override {
        cout << "Drawing Rectangle with width: " << width << " and height: " << height << endl;
    }

    double calculateArea() const override {
        return width * height;
    }
};

int main() {
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(4.0, 6.0);

    circle->draw();
    cout << "Circle Area: " << circle->calculateArea() << endl;

    rectangle->draw();
    cout << "Rectangle Area: " << rectangle->calculateArea() << endl;

    delete circle;
    delete rectangle;

    return 0;
}
