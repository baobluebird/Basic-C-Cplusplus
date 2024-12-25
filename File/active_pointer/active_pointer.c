#include <stdio.h>

int main() {
    FILE *fp = fopen("example.txt", "r");
    char buffer[20];

    // Đọc 10 byte từ file
    fread(buffer, 1, 10, fp); 
    printf("Position after fread: %ld\n", ftell(fp));

    // Di chuyển con trỏ file về đầu
    rewind(fp);
    printf("Position after rewind: %ld\n", ftell(fp));

    fclose(fp);
    return 0;
}
