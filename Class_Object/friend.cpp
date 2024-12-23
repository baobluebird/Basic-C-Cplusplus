// #include <iostream>
// using namespace std;

// class Box {
// private:
//     double length;
//     double breadth;
//     double height;

// public:
//     Box(double l, double b, double h) : length(l), breadth(b), height(h) {}

//     // Declare friend function
//     friend double calculateVolume(Box& b);  
//     // friend double calculateVolume(Box& b){
//     // // Access Box private members
//     //     return b.length * b.breadth * b.height;
//     // }
// };

// // Define your function calculateVolume
// double calculateVolume(Box& b) {
//     return b.length * b.breadth * b.height;
// }

// int main() {
//     Box box(3.0, 4.0, 5.0);
//     cout << "Volume of the box: " << calculateVolume(box) << endl;

//     return 0;
// }

#include <iostream>
using namespace std;

class ClassA {
private:
    int valueA;

public:
    ClassA(int val) : valueA(val) {}

    friend void show(ClassA& objA, int extraValue);  
};

class ClassB {
public:
    void display(ClassA& objA, int extraValue) {
        show(objA, extraValue);  
    }
};

void show(ClassA& objA, int extraValue) {
    cout << "Value of A: " << objA.valueA << ", Extra Value: " << extraValue << endl;
}

int main() {
    ClassA objA(5);
    ClassB objB;
    objB.display(objA, 10); 

    return 0;
}
