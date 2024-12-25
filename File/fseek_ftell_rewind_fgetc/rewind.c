#include <stdio.h>

int main() {
    FILE *fp = fopen("example.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char buffer[100];
    fgets(buffer, sizeof(buffer), fp);  // Đọc dòng đầu tiên
    printf("First read: %s", buffer);
    long position1 = ftell(fp);
    printf("Current position: %ld\n", position1);
    rewind(fp);  // Đưa con trỏ về đầu file
    long position2 = ftell(fp);
    printf("Current position: %ld\n", position2);
    fgets(buffer, sizeof(buffer), fp);  // Đọc lại dòng đầu tiên
    printf("Second read: %s", buffer);

    fclose(fp);
    return 0;
}
