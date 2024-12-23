#include <iostream>
#include <memory>

class B; // Declare before so that class A can refer to

class A
{
public:
    std::shared_ptr<B> bPtr; // shared_ptr refers to B
    ~A()
    {
        std::cout << "A is destroyed." << std::endl;
    }
};

class B
{
public:
    std::shared_ptr<A> aPtr; // shared_ptr refers to A
    ~B()
    {
        std::cout << "B is destroyed." << std::endl;
    }
};

int main()
{
    std::shared_ptr<A> a = std::make_shared<A>();
    std::cout<< a.use_count() << std::endl;
    std::shared_ptr<B> b = std::make_shared<B>();
    std::cout<< b.use_count() << std::endl;
    a->bPtr = b; // A refers to B
    std::cout<< a.use_count() << std::endl;
    std::cout<< b.use_count() << std::endl;
    b->aPtr = a; // B references back A
    std::cout<< a.use_count() << std::endl;
    std::cout<< b.use_count() << std::endl;
    // At this point, the reference count of both a and b is > 0
    // This leads to a memory leak because neither object is destroyed.

    return 0; // End the program without releasing A and B
}