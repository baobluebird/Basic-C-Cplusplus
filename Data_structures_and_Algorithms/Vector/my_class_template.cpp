#include <iostream>
#include <stdexcept>

template <typename T>
class Vector
{
private:
    T *data;
    size_t capacity; //
    size_t size;     // = unsigned int

    void realloc(size_t new_capacity)
    {
        T *new_data = new T[new_capacity]; // new int[size]
        if (new_data == nullptr)
        {
            throw std::out_of_range("Allocation failed");
        }
        for (size_t i = 0; i < size; ++i)
        { // size ở đây là của đối tượng khi được tạo ra
            new_data[i] = data[i];
        }
        delete[] data;   // delete old_data
        data = new_data; // insert new data
        capacity = new_capacity;
    }

public:
class Iterator
    {
    private:
        T *ptr; // Con trỏ đến phần tử hiện tại
    public:
        explicit Iterator(T *ptr) : ptr(ptr) {}

        T &operator*() { return *ptr; }                // Dereference operator
        Iterator &operator++()                         // Prefix increment
        {
            ++ptr;
            return *this;
        }
        Iterator operator++(int)                       // Postfix increment
        {
            Iterator temp = *this;
            ++ptr;
            return temp;
        }
        Iterator &operator--()                         // Prefix decrement
        {
            --ptr;
            return *this;
        }
        Iterator operator--(int)                       // Postfix decrement
        {
            Iterator temp = *this;
            --ptr;
            return temp;
        }
        bool operator!=(const Iterator &other) const { return ptr != other.ptr; }
        bool operator==(const Iterator &other) const { return ptr == other.ptr; }
    };
    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }

    // Default Constructor
    // constructor dung cho vector<data_type> vec;
    Vector()
    {
        data = nullptr;
        capacity = 0;
        size = 0;
    }
    // Constructor voi kich thuoc va gia tri mac dinh
    // constructor dung cho vector<data_type> vec(10) (10 phan tu mac dinh value la 0) or vec(10,1) (10 phan tu value la 1)
    Vector(size_t init_size, const T &value = T()) // T() là cách gọi constructor mặc định kiểu dữ liệu T, VD: T là int thì T() trả về 0, string thì trả về ""
        : data(new T[init_size]), capacity(init_size), size(init_size)
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = value;
        }
    }
    // Constructor danh sach khoi tao
    // constructor dung cho vector<data_type> vec{1,2,3,4,5}
    Vector(std::initializer_list<T> init_list)
        : data(new T[init_list.size()]), capacity(init_list.size()), size(init_list.size())
    {
        size_t index = 0;
        for (const T &element : init_list)
        {
            data[index++] = element;
        }
    }
    // Copy constructor
    // constructor dung cho viec gan vector nay cho vector khac
    Vector(const Vector &other_vector)
        : data(new T[other_vector.capacity]), capacity(other_vector.capacity), size(other_vector.size)
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other_vector.data[i];
        }
    }
    // Move constructor
    Vector(Vector &&other) noexcept
        : data(other.data), capacity(other.capacity), size(other.size)
    {
        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;
    }
    // Move assigment operator
    // Phiên bản cải thiện của operator = dưới, dùng Move Semantics
    Vector &operator=(Vector &&other) noexcept
    {
        if (this == &other)
            return *this;
        delete[] data;

        data = other.data;
        size = other.size;
        capacity = other.capacity;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;

        return *this;
    }
    // Copy assigment operator
    Vector &operator=(const Vector &other_vector)
    {
        if (this == &other_vector)
            return *this; // Kiểm tra xem đối tượng hiện tai có cùng với other_vector không, nếu trùng thì trả về chính nó để tránh infinity loop
        delete[] data;
        data = new T[other_vector.capacity];
        capacity = other_vector.capacity;
        size = other_vector.capacity;
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other_vector.data[i];
        }
        return *this;
    }
    // Operator truy cap
    T &operator[](size_t index)
    {
        if (data == nullptr)
        {
            throw std::out_of_range("Out of range");
        }
        if (index >= size)
        {
            throw std::out_of_range("Accessing invalid vector.");
        }
        return data[index];
    }

    // Get first element
    T &front()
    {
        if (size == 0)
        {
            throw std::out_of_range("Vector don't have anything");
        }
        return data[0];
    }
    // Get last element
    T &back()
    {
        if (size == 0)
        {
            throw std::out_of_range("Vector don't have anything");
        }
        return data[size - 1];
    }
    // Add element at last vector by push_back
    void insert(const T &value, size_t position)
    {
        if(size == capacity){
            realloc(capacity == 0 ? 1 : capacity * 2);
        }
        if(position <= 0){
            push_front(value);
            return;
        }else if(position >= size){
            push_back(value);
            return;
        }
        for(size_t i = size; i > position; --i){
            data[i] = data[i-1];
        }
        data[position] = value;
        ++size;
    }
    // Add element at first vector by push_back
    void push_front(const T &value)
    {
        if (size == capacity)
        {
            // Neu chua khoi tao so luong phan tu thi capacity == 0 nen ta se tao capacity = 1 cho no de add element vao
            realloc(capacity == 0 ? 1 : capacity * 2);
        }
        //++ la vi ta co the push_back lien tiep (khong tru 1 la vi ta dang add vao cuoi vetor)
        
        for(size_t i = size; i > 0; --i){
            data[i] = data[i-1]; //data[5] = data[4] = 5
        }
        //use pointer
        // for(T *ptr = data + size; ptr != data; --ptr){
        //     *ptr = *(ptr-1);
        // }
        data[0] = value;
        ++size;
    }
    // Add element at last vector by push_back
    void push_back(const T &value)
    {
        if (size == capacity)
        {
            // Neu chua khoi tao so luong phan tu thi capacity == 0 nen ta se tao capacity = 1 cho no de add element vao
            realloc(capacity == 0 ? 1 : capacity * 2);
        }
        //++ la vi ta co the push_back lien tiep (khong tru 1 la vi ta dang add vao cuoi vetor)
        data[size++] = value;
    }
    // Delete element at first vector by pop_back()
    void pop_back()
    {
        if (size == 0)
        {
            throw std::out_of_range("Vector is empty");
        }
        data[size - 1].~T(); // Call destructor if size is 1;
        // Just kick that element out of the vector, the value is still stored in memory,
        // only deleted when the memory is freed (destructor or clear);
        --size;
    }
    // Change size vector
    void resize(size_t new_size, const T &value = T())
    {
        if (new_size > capacity)
        {
            realloc(new_size);
        }
        if (new_size > size)
        {
            for (size_t i = size; i < new_size; ++i)
            {
                data[i] = value;
            }
        }
        else if (new_size < size)
        {
            for(size_t i = new_size; i < size; ++i)
            {
                data[i].~T();
            }
        }
        size = new_size;
    }

    void clear()
    {
        size = 0;
    }

    size_t get_size()
    {
        return size;
    }

    size_t get_capacity()
    {
        return capacity;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void print()
    {
        std::cout << "[";
        for (size_t i = 0; i < size; ++i)
        {
            std::cout << data[i] << " ";
            if (i != size - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]";
    }
    void printByIterator()
    {
        std::cout << "[";
        for(Iterator it = begin(); it != end(); ++it){
            std::cout << *it << ", ";
        }
        std::cout << "]";
    }

    ~Vector()
    {
        delete[] data;
    }
};

int main()
{
    // // Default constructor
    // Vector<int> v1;
    // // Constructor with size and default value
    // Vector<int> v2(5, 1); // 1 1 1 1 1
    // Vector<int> v3(5);    // 0 0 0 0 0
    // std::cout << "Constructor with size and default value:" << std::endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     std::cout << v2[i] << " ";
    // }
    // std::cout << std::endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     std::cout << v3[i] << " ";
    // }
    // std::cout << std::endl;
    // // Constructor with list
    // Vector<int> v4{1, 2, 3, 4, 5};
    // std::cout << "Constructor with list:" << std::endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     std::cout << v4[i] << " ";
    // }
    // std::cout << std::endl;
    // // Copy constructor
    // Vector<int> v_copy_1{1, 2, 3};
    // Vector<int> v_copy_2(v_copy_1);
    // std::cout << "Copy constructor:" << std::endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     std::cout << v_copy_2[i] << " ";
    // }
    // std::cout << std::endl;
    // // Move constructor
    // Vector<int> v_move_1{1, 2, 3};
    // Vector<int> v_move_2(std::move(v_move_1));
    // std::cout << "Move constructor after move v_move_1:" << std::endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     std::cout << v_move_2[i] << " ";
    // }
    // std::cout << std::endl;
    // std::cout << "Vector base after move:" << std::endl;
    // // if (v_move_1[0] == 0) {
    // //     std::cout << "Error." << std::endl;
    // // }
    // // Copy Assignment Operator
    // Vector<int> vec1{1, 2, 3};
    // Vector<int> vec2{10, 20, 30, 40};
    // vec2 = vec1;
    // std::cout << "Copy Assignment Operator:" << std::endl;
    // for (size_t i = 0; i < 3; i++)
    // {
    //     std::cout << vec2[i] << " ";
    // }
    // std::cout << std::endl;
    // // Move assignment operator
    // Vector<int> vec3{1, 2, 3};
    // Vector<int> vec4{10, 20};
    // vec4 = std::move(vec1);
    // std::cout << "Move assignment operator: vector vec2 after move ";
    // std::cout << std::endl;
    // for (size_t i = 0; i < 3; i++)
    // {
    //     std::cout << vec2[i] << " ";
    // }
    // std::cout << std::endl;

    // Method of vector
    Vector<int> vector;
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(4);
    vector.push_back(5);
    std::cout << "Add element use push_back: ";
    vector.print();
    std::cout << std::endl;
    vector.push_front(0);
    vector.print();
    std::cout << std::endl;
    std::cout << "Access by vector[1]: " << vector[1];
    std::cout << std::endl;
    // Print first element
    std::cout << "First element: " << vector.front() << std::endl;
    // Print last element
    std::cout << "Last element: " << vector.back() << std::endl;
    // Change size vector
    std::cout << "Change size vector use resize (new_size < size): " << std::endl;
    vector.resize(3);
    vector.print();
    std::cout << std::endl;
    std::cout << "Change size vector use resize (new_size > size): " << std::endl;
    vector.resize(5);
    vector.print();
    std::cout << std::endl;
    //Delete last element
    std::cout << "Delete last element: " << std::endl;
    vector.pop_back();
    vector.print();
    std::cout << std::endl;
    //Get size, capacity
    std::cout << "Get size: " << vector.get_size() << ", Get capacity: " << vector.get_capacity() << std::endl;
    //Clear
    vector.clear();
    std::cout << "Vector after use clear: " << std::endl;
    vector.print();
    std::cout << std::endl;
    //Check empty
    std::cout << "Check vector isEmpty: " << vector.isEmpty() << std::endl;
    //Use operator =
    Vector<int> vector2{1,2,3};
    vector2[0] = 10;
    std::cout << "Use vector2[0] = 1" << std::endl;
    vector2.print();
    std::cout << std::endl;
    std::cout << "Insert any position: " << std::endl;
    vector2.insert(20,1);
    vector2.printByIterator();

    return 0;
}