#include <stdio.h>
#include <string.h>
int main() {
    FILE *fp = fopen("example.txt", "r+");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    fseek(fp, 5, SEEK_SET);  // Di chuyển đến byte thứ 5
    char str[] = "hi";
    int a = fputs(str,fp);
    printf("%d", a);
    //fseek(fp, 5, SEEK_SET);

    char ch = fgetc(fp);     // Đọc ký tự tại vị trí đó
    printf("Character at position 5: %c\n", ch);

    fclose(fp);
    return 0;
}
