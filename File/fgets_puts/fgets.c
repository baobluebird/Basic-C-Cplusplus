#include <stdio.h>

int main() {
    FILE *fp = fopen("example.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char buffer[100];
    //char *buffer;
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);  // In từng dòng từ file
    }

    fclose(fp);
    return 0;
}
