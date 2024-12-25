#include <stdio.h>

int main() {
    FILE *fp = fopen("example.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    fgetc(fp);  // Đọc một ký tự
    printf("%c\n", fgetc(fp));
    long position = ftell(fp);
    printf("Current position: %ld\n", position);

    fclose(fp);
    return 0;
}
