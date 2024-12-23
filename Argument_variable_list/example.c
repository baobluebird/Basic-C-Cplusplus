#include <stdio.h>
#include <stdarg.h>

int sum(int num, ...) {
    int total = 0;
    va_list args;
    va_start(args, num);   // Khởi tạo danh sách tham số

    for (int i = 0; i < num; i++) {
        total += va_arg(args, int);  // Lấy từng tham số và cộng vào total
    }

    va_end(args);           // Dọn dẹp tài nguyên
    return total;
}

int main() {
    printf("Sum = %d\n", sum(4, 10, 20, 30, 40));  // Tính tổng của 4 tham số
    printf("Sum = %d\n", sum(2, 5, 7));            // Tính tổng của 2 tham số
    return 0;
}
