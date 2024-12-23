#include <iostream>
#include <chrono>
#pragma pack(1)

using namespace std;

class MyClass_UnDataAligned {
public:
    char a;     // 1 byte
    double b;   // 8 bytes
    int c;      // 4 bytes
};

int main() {
    const int N = 10000000; 
    cout << "Size of UnDataAligned: " << sizeof(MyClass_UnDataAligned) << " bytes" << endl;

  
    auto start = chrono::high_resolution_clock::now();
    
    MyClass_UnDataAligned *arr = new MyClass_UnDataAligned[N];
    
    for (int i = 0; i < N; ++i) {
        arr[i].a = 'A';
        arr[i].b = 3.14;
        arr[i].c = 42;
    }
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Time taken (UnDataAligned): " << duration.count() << " seconds" << endl;
    
    delete[] arr;
    return 0;
}