#include <stdio.h>

int main() {
    char str[] = "Hello, World!";
    int i = 0;

    printf("Output: ");
    while (str[i] != '\0') { // Lặp qua từng ký tự cho đến khi gặp ký tự kết thúc chuỗi
        putchar(str[i]); // In từng ký tự
        i++;
    }
    printf("\n");

    return 0;
}
