#include <stdio.h>

void addTen(int *x) {
    printf("x in addTen: %p\n", x);  // Kết quả: x sẽ là 15
    int *b;
    x = b;  // Thay đổi giá trị của x thông qua con trỏ
    printf("x in addTen: %p\n", x);  // Kết quả: x sẽ là 15
}

int main() {
    int a = 5;
    addTen(&a);  // Truyền địa chỉ của a vào hàm
    printf("a after addTen: %d\n", a);  // Kết quả: a sẽ là 15
    return 0;
}
