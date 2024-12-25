#include <iostream>

int main() {
    int* arr = new int[5];  // Cấp phát bộ nhớ cho mảng 5 phần tử kiểu int

    // In giá trị của mảng (mảng chưa được khởi tạo nên giá trị sẽ là rác)
    for (int i = 0; i < 5; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;  // Giá trị chưa xác định (rác)
    }

    // Khởi tạo giá trị cho mảng
    for (int i = 0; i < 5; i++) {
        arr[i] = (i + 1) * 10;  // Gán giá trị cho các phần tử
    }

    // In lại giá trị sau khi khởi tạo
    for (int i = 0; i < 5; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;  // Giá trị đã khởi tạo
    }

    delete[] arr;  // Giải phóng bộ nhớ
    return 0;
}
