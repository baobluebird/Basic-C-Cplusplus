#include <iostream>
#include <stdexcept> // Thu vien de quan ly ngoai le

// Dinh nghia template Vector

template <typename T>
class Vector {
    private:
        T* data;               // Con tro den mang du lieu
        size_t capacity;       // So phan tu toi da vector co the chua (dung luong)
        size_t size;           // So phan tu hien co trong vector

        // Ham cap phat lai bo nho khi can
        void reallocate(size_t new_capacity) {
            T* new_data = new T[new_capacity]; // Cap phat bo nho moi
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i]; // Sao chep du lieu cu sang bo nho moi
            }
            delete[] data; // Giai phong bo nho cu
            data = new_data;
            capacity = new_capacity;
        }

    public:
        // Constructor khong tham so
        Vector() : data(nullptr), capacity(0), size(0) {}

        // Constructor voi kich thuoc khoi tao
        Vector(size_t initial_size, const T& value = T()) 
            : data(new T[initial_size]), capacity(initial_size), size(initial_size) 
        {
            for (size_t i = 0; i < size; ++i) {
                data[i] = value; // Khoi tao cac phan tu bang gia tri cho truoc
            }
        }

        // Constructor với initializer_list
        Vector(std::initializer_list<T> init_list) 
        : data(new T[init_list.size()]), capacity(init_list.size()), size(init_list.size()) {
        size_t index = 0;
        for (const T& element : init_list) {
            data[index++] = element;
        }
        }

        // Destructor
        ~Vector() {
            delete[] data; // Giai phong bo nho 
        }

        // Constructor sao chep
        Vector(const Vector& other) 
            : data(new T[other.capacity]), capacity(other.capacity), size(other.size) 
        {
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i]; // Sao chep du lieu tu vector khac
            }
        }

        // Toan tu gan
        Vector& operator=(const Vector& other) {
            if (this == &other) return *this; 
            delete[] data; // Giai phong bo nho cu
            data = new T[other.capacity];
            capacity = other.capacity;
            size = other.size;
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i]; // Sao chep du lieu
            }
            return *this;
        }

        // Truy xuat phan tu theo chi muc
        T& operator[](size_t index) {
            if (index >= size) {
                throw std::out_of_range("Index out of range"); // Kiem tra vuot gioi han
            }
            return data[index];
        }

        // Truy xuat phan tu (const)
        // const T& operator[](size_t index) const {
        //     if (index >= size) {
        //         throw std::out_of_range("Index out of range");
        //     }
        //     return data[index];
        // }

        // Lay phan tu dau tien
        T& front() {
            if (size == 0) throw std::out_of_range("Vector is empty");
            return data[0];
        }

        // Lay phan tu cuoi cung
        T& back() {
            if (size == 0) throw std::out_of_range("Vector is empty");
            return data[size - 1];
        }

        // Them phan tu vao cuoi vector
        void push_back(const T& value) {
            if (size == capacity) {
                reallocate(capacity == 0 ? 1 : capacity * 2);
            }
            data[size++] = value;
        }

        // Xoa phan tu cuoi cung
        void pop_back() {
            if (size > 0) {
                --size;
            }
        }

        // Thay doi kich thuoc vector
        void resize(size_t new_size, const T& value = T()) {
            if (new_size > capacity) {
                reallocate(new_size);
            }
            if (new_size > size) {
                for (size_t i = size; i < new_size; ++i) {
                    data[i] = value; // Them gia tri moi vao vector
                }
            }
            size = new_size;
        }

        // Xoa tat ca cac phan tu
        void clear() {
            size = 0;
        }

        // Lay kich thuoc hien tai
        size_t get_size() const {
            return size;
        }

        // Lay dung luong cua vector
        size_t get_capacity() const {
            return capacity;
        }

        // Kiem tra vector co rong hay khong
        bool empty() const {
            return size == 0;
        }

        // In toan bo cac phan tu
        void print() const {
            std::cout << "[";
            for (size_t i = 0; i < size; ++i) {
                std::cout << data[i];
                if (i != size - 1) std::cout << ", ";
            }
            std::cout << "]\n";
        }
};

int main() {
    Vector<int> vec; // Tao mot doi tuong vector mac dinh
    
    // 1. Them phan tu vao cuoi vector
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    std::cout << "Vector sau khi them phan tu: ";
    vec.print();

    //2. In phan tu dau tien
    try {
        std::cout << "Phan tu dau tien: " << vec.front() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }

    // 3. In phan tu cuoi cung
    try {
        std::cout << "Phan tu cuoi cung: " << vec.back() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }

    // 4. Thay doi kich thuoc vector (resize)
    std::cout << "Thay doi kich thuoc vector: ";
    vec.resize(3); // Resize vector len 7 va gan gia tri 100 cho cac phan tu moi
    vec.print();

    // 5. Xoa phan tu cuoi cung
    vec.pop_back();
    std::cout << "Vector sau khi xoa phan tu cuoi: ";
    vec.print();

    // 6. Lay kich thuoc va dung luong cua vector
    std::cout << "Kich thuoc vector: " << vec.get_size() << std::endl;
    std::cout << "Dung luong vector: " << vec.get_capacity() << std::endl;

    // 7. Xoa tat ca phan tu trong vector
    vec.clear();
    std::cout << "Vector sau khi clear: ";
    vec.print();

    // 8. Kiem tra vector co rong hay khong
    std::cout << "Vector co rong hay khong: " << (vec.empty() ? "Co" : "Khong") << std::endl;

    //9. Copy constructor
    Vector<int> vec1 = {1, 2, 3};
    Vector<int> vec2 = vec1;  // Copy constructor sẽ được gọi
    std::cout<<"vector sau khi sao chep: \n";
    vec2.print();

    //10. Toan tu gan
    Vector<int> vec3 = {4, 5, 6};
    vec3[0] = 40;
    std::cout << vec3[0];
    Vector<int> vec4;
    vec4 = vec3;  // Toán tử gán sẽ được gọi
    std::cout<<"vector sau khi duoc gan: \n";
    vec3.print();

    //11.truy xuat phan tu ngoai pham vi luu tru
    // std::cout<<"phan tu tai vi tri so 5: \n";
    //std::cout<<vec4[5];

    //12. test capacity
    std::cout<<"bo nho toi da hien tai cua vecto: ";
    std::cout<<vec4.get_capacity();


    return 0;
}

