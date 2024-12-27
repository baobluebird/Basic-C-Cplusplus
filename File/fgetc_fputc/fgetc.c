#include <stdio.h>

int main() {
    FILE *fp = fopen("example.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char c;
    while ((c = fgetc(fp)) != EOF) { // Đọc từng ký tự
        printf("%c", c); // In ra từng ký tự
    }

    fclose(fp);
    return 0;
}
