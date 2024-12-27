#include <stdio.h>

int main() {
    char c;

    printf("Enter a character: ");
    c = getchar(); // Đọc một ký tự từ bàn phím
    printf("You entered: ");
    putchar(c); // In ký tự vừa nhập
    printf("\n");

    return 0;
}
