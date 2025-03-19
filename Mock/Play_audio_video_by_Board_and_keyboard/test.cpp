#include <bits/stdc++.h>

class Base{
    private:
        int x;
        int y;
public:
    virtual void print(){
        std::cout << "Base" << std::endl;
    }

    virtual void setZ1(int z1){}
};

class Derived1 : public Base{
private:
    int z1;
    int w1;
public:
    void print() override{
        std::cout << "Derived" << std::endl;
    }
    
    void setZ1(int z1) override{
        this->z1 = z1;
    }
};

class Derived2 : public Base{
private:
    int z2;
    int w2;
public:
    
};

int main(){
    Base* b = new Derived1();
    b->setZ1(10);
    return 0;
}