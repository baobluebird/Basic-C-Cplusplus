#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class A{
    private:
        int a;
    public:
        A(){
            cout << "Constructor of A" << endl;
        }
        ~A(){
            cout << "Destructor of A" << endl;
        }
};

class B {
    private:
        int b;
        //A a;
    public:
        B(){
            cout << "Constructor of B" << endl;
        }
        ~B(){
            cout << "Destructor of B" << endl;
        }
};

class C{
    private:
        int c;
        vector<B> listB;
        //B a[5];
    public:
        C(){
            cout << "Constructor of C" << endl;
        }
        ~C(){
            cout << "Destructor of C" << endl;
        }
        void addB(){
            B b;
            listB.push_back(b);
        }
};
int main(){
    C c;
    c.addB();
    return 0;
}