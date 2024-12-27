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
        putchar(c); // In từng ký tự
    }

    if (feof(fp))
    {
        printf("\nEnd of file reached.\n");
    }

    fclose(fp);
}