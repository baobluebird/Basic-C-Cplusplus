#include <stdio.h>

int main()
{
    FILE *fp = fopen("example.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char c;
    while ((c = fgetc(fp)) != EOF)
    {
        if (ferror(fp))
        { // Kiểm tra lỗi
            perror("Error reading file");
            break;
        }
        putchar(c);
    }

    fclose(fp);
}