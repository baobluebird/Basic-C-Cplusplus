#include <iostream>

// Define UniquePointer class
template <typename T>
class UniquePointer
{
private:
    T *ptr; // Raw pointer

public:
    // Constructor
    explicit UniquePointer(T *p = nullptr) : ptr(p) {}

    // Destructor
    ~UniquePointer()
    {
        delete ptr;
    }

    // Delete copy constructor and copy assignment operator
    UniquePointer(const UniquePointer &) = delete;
    UniquePointer &operator=(const UniquePointer &) = delete;

    // Move constructor
    UniquePointer(UniquePointer &&other) noexcept : ptr(other.ptr)
    {
        other.ptr = nullptr;
    }

    // Move assignment operator
    UniquePointer &operator=(UniquePointer &&other) noexcept
    {
        if (this != &other)
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // Overload operators * and ->
    T &operator*() const
    {
        return *ptr;
    }

    T *operator->() const
    {
        return ptr;
    }
};

// Define SharedPointer class
template <typename T>
class SharedPointer
{
private:
    T *ptr;           // Raw pointer
    size_t *refCount; // Count the number of references

public:
    // Constructor
    explicit SharedPointer(T *p = nullptr) : ptr(p), refCount(new size_t(1)) {}

    // Copy constructor
    SharedPointer(const SharedPointer &other) : ptr(other.ptr), refCount(other.refCount)
    {
        (*refCount)++;
    }

    // Copy assignment operator
    SharedPointer &operator=(const SharedPointer &other)
    {
        if (this != &other)
        {
            release();
            ptr = other.ptr;
            refCount = other.refCount;
            (*refCount)++;
        }
        return *this;
    }

    // Constructor to support WeakPointer::lock
    explicit SharedPointer(T *p, size_t *refCnt) : ptr(p), refCount(refCnt)
    {
        if (refCnt)
            (*refCount)++;
    }

    // Destructor
    ~SharedPointer()
    {
        release();
    }

    // Getter for ptr and refCount
    T *getPtr() const { return ptr; }
    size_t *getRefCount() const { return refCount; }

    // Overload operators * and ->
    T &operator*() const
    {
        return *ptr;
    }

    T *operator->() const
    {
        return ptr;
    }

private:
    void release()
    {
        if (--(*refCount) == 0)
        {
            delete ptr;
            delete refCount;
        }
    }
};

// Define WeakPointer class
template <typename T>
class WeakPointer
{
private:
    T *ptr;           // Raw pointer
    size_t *refCount; // Count the number of references

public:
    // Constructor from SharedPointer
    WeakPointer(const SharedPointer<T> &sharedPtr)
        : ptr(sharedPtr.getPtr()), refCount(sharedPtr.getRefCount()) {}

    // Check if the pointer is still valid
    bool expired() const
    {
        return *refCount == 0;
    }

    // Convert to SharedPointer
    SharedPointer<T> lock() const
    {
        return expired() ? SharedPointer<T>(nullptr) : SharedPointer<T>(ptr, refCount);
    }
};

// Main function to check smart pointers
int main()
{
    // Test UniquePointer
    UniquePointer<int> uniquePtr(new int(42));
    std::cout << "UniquePointer value: " << *uniquePtr << std::endl;
    UniquePointer<int> uniquePtr2 = std::move(uniquePtr);
    uniquePtr2 = std::move(uniquePtr);
    // Test SharedPointer
    SharedPointer<int> sharedPtr1(new int(100));
    
    SharedPointer<int> sharedPtr2 = sharedPtr1; // Share ownership
    // SharedPointer<int> sharedPtr2;
    // sharedPtr2 = sharedPtr1; 
    std::cout << "SharedPointer value (sharedPtr2): " << *sharedPtr2 << std::endl;
    std::cout << "SharedPointer value (sharedPtr1): " << *sharedPtr1 << std::endl;

    // Test WeakPointer
    SharedPointer<int> sharedPtr(new int(200));
    WeakPointer<int> weakPtr(sharedPtr); // Create WeakPointer from SharedPointer
    if (!weakPtr.expired())
    {
        auto lockedSharedPtr = weakPtr.lock();
        std::cout << "WeakPointer value: " << *lockedSharedPtr << std::endl;
    }
    else
    {
        std::cout << "WeakPointer expired." << std::endl;
    }

    return 0;
}