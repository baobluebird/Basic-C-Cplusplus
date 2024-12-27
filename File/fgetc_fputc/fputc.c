#include <stdio.h>

int main() {
    FILE *fp = fopen("example.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char str[] = "Hello, World!";
    for (int i = 0; str[i] != '\0'; i++) { // Lặp qua từng ký tự trong chuỗi
        fputc(str[i], fp); // Ghi từng ký tự vào tệp
    }

    fclose(fp);
    return 0;
}
