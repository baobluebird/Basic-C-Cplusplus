#include <stdio.h>

int main() {
    FILE *fp = fopen("example.txt", "r+");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);  // In từng ký tự ra màn hình
    }
    fseek(fp,0,SEEK_END);
    long int a =  ftell(fp);
    printf("%d", a);
    fputs("oke",fp);
    fclose(fp);
    return 0;
}
