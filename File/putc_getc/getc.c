#include <stdio.h>

int main() {
    FILE *fp = fopen("example.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    putc('H', fp); // Ghi ký tự 'H'
    putc('i', fp); // Ghi ký tự 'i'
    putc('\n', fp); // Ghi ký tự xuống dòng
    fclose(fp);

    return 0;
}
