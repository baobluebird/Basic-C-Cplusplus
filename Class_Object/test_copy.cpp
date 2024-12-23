#include <iostream>
using namespace std;

class Car {
private:
    string make;
    int year;
    int * user;
public:
    // Parameterized Constructor
    Car(string m, int y, int z) {
        make = m;
        year = y;
        user = new int(z);
        
    }

    // Copy Constructor
    Car(const Car &other) {
        make = other.make;
        year = other.year;
        user = new int(*other.user);
        cout << "Copy constructor called. Make: " << make << ", Year: " << year <<" " << *user << endl;
    }

    void display() {
        cout << "Car Make: " << make << ", Year: " << year <<" " << *user << endl;
    }
};

int main() {
    Car car2("Toyota", 2020, 3);  // Parameterized constructor is called
    Car car3 = car2;           // Copy constructor is called
    car3.display();
    return 0;
}