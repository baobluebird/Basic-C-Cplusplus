#include <iostream>
#include <memory>

class B; // Declare before so that class A can refer to it

class A
{
public:
    std::weak_ptr<B> bPtr; // shared_ptr references B
    ~A()
    {
        std::cout << "A is destroyed." << std::endl;
    }
};

class B
{
public:
    std::shared_ptr<A> aPtr; // weak_ptr references A (does not increase reference count)
    ~B()
    {
        std::cout << "B is destroyed." << std::endl;
    }
};

int main()
{
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->bPtr = b; // A references B

    b->aPtr = a; // B weakly references A (does not increase reference count)

    // When main ends, shared_ptr decrements the reference count of A and B to 0
    // Resources are properly freed.

    return 0;
}