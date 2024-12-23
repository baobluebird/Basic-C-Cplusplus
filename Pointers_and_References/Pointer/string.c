#include <stdio.h>

int main() {
    char *str = "Hello, World!";  // Con trỏ trỏ đến chuỗi "Hello, World!"

    printf("String: %c\n", *(str+0));    // In ra chuỗi

    return 0;
}
