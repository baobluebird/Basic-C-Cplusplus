#include <iostream>
#include <chrono>
using namespace std;

class MyClass_Unoptimized {
public:
    char a;     // 1 byte
    double b;   // 8 bytes
    int c;      // 4 bytes
};

int main() {

    cout << "Size of Unoptimized: " << sizeof(MyClass_Unoptimized) << " bytes" << endl;

    const int N = 10000000; // Number of objects

    // Đo thời gian khởi tạo đối tượng MyClass_Unoptimized
    auto start = chrono::high_resolution_clock::now();
    
    MyClass_Unoptimized *arr = new MyClass_Unoptimized[N];
    
    for (int i = 0; i < N; ++i) {
        arr[i].a = 'A';
        arr[i].b = 3.14;
        arr[i].c = 42;
    }
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Time taken (Unoptimized): " << duration.count() << " seconds" << endl;
    
    delete[] arr;
    return 0;
}
