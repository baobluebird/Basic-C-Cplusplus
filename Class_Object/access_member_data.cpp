#include <iostream>
using namespace std;

class BaseClass {
public:
    int publicVar;  // Public Data Member: can be accessed from outside the class
protected:
    int protectedVar;  // Protected Data Member: can be accessed within the class and derived classes
private:
    int privateVar;  // Private Data Member: can only be accessed within the class

public:
    // Constructor to initialize values of data members
    BaseClass(int publicVal, int protectedVal, int privateVal) {
        publicVar = publicVal;
        protectedVar = protectedVal;
        privateVar = privateVal;
    }
    
    // Getter and Setter for privateVar (private member)
    void setPrivateVar(int val) {
        privateVar = val;
    }

    int getPrivateVar() {
        return privateVar;
    }

};

// Derived class that inherits from BaseClass
class DerivedClass : public BaseClass {
public:
    DerivedClass(int publicVal, int protectedVal, int privateVal)
        : BaseClass(publicVal, protectedVal, privateVal) {}

    void accessProtectedVar() {
        // Can access protectedVar because it's inherited from BaseClass
        cout << "Protected Variable from Derived Class: " << protectedVar << endl;
    }
};

int main() {
    BaseClass baseObj(10, 20, 30);
    DerivedClass derivedObj(40, 50, 60);

    // Correct access to publicVar
    cout << "Accessing Public Variable from Base Class: " << baseObj.publicVar << endl;  // Correct

    // Trying to access Private directly (will cause error)
    // cout << "Accessing Private Variable from Base Class: " << baseObj.privateVar << endl;  // Error: privateVar cannot be accessed from outside

    // Update privateVar through setter
    baseObj.setPrivateVar(100);
    cout << "Updated Private Variable (via setter): " << baseObj.getPrivateVar() << endl;

    // Trying to access Protected directly (will cause error if outside class or derived class)
    // cout << "Accessing Protected Variable from Base Class: " << baseObj.protectedVar << endl;  // Error: cannot access from outside class or derived class

    // Correct access from derived class (publicVar is inherited)
    cout << "Accessing Public Variable from Derived Class: " << derivedObj.publicVar << endl;  // Correct
    derivedObj.accessProtectedVar();  // Access protectedVar within derived class
    derivedObj.getPrivateVar();
    // Trying to access Private directly in derived class (will cause error)
    // derivedObj.privateVar = 100;  // Error: privateVar cannot be accessed in derived class


    return 0;
}
