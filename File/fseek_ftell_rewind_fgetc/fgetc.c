#include <stdio.h>

int main() {
    FILE *fp = fopen("example.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);  // In từng ký tự ra màn hình
    }

    fclose(fp);
    return 0;
}
