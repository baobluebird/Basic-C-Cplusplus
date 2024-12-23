#include <iostream>
#include <chrono>
using namespace std;

class MyClass_Optimized {
public:
    double b;   // 8 bytes
    int c;      // 4 bytes
    char a;     // 1 byte
};

int main() {

    cout << "Size of Optimized: " << sizeof(MyClass_Optimized) << " bytes" << endl;

    const int N = 10000000; 

    auto start = chrono::high_resolution_clock::now();
    
    MyClass_Optimized *arr = new MyClass_Optimized[N];
    
    for (int i = 0; i < N; ++i) {
        arr[i].a = 'A';
        arr[i].b = 3.14;
        arr[i].c = 42;
    }
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Time taken (Optimized): " << duration.count() << " seconds" << endl;
    
    delete[] arr;
    return 0;
}
