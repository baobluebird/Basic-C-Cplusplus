#include <iostream>
using namespace std;

int main() {
    int **arr = new int *[10];  // Tạo mảng động gồm 10 con trỏ đến số nguyên

    // Khởi tạo mỗi con trỏ trong mảng
    for (int i = 0; i < 10; ++i) {
        arr[i] = new int;       // Cấp phát bộ nhớ động cho mỗi số nguyên
        *arr[i] = i;            // Gán giá trị cho bộ nhớ đã cấp phát
    }

    // In các giá trị
    for (int i = 0; i < 10; ++i) {
        cout << "Value at arr[" << i << "]: " << *arr[i] << endl;
    }

    // Giải phóng bộ nhớ đã cấp phát
    for (int i = 0; i < 10; ++i) {
        delete arr[i];          // Giải phóng bộ nhớ cho mỗi số nguyên
    }
    delete[] arr;               // Giải phóng bộ nhớ cho mảng con trỏ

    return 0;
}
