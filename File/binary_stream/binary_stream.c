#include <stdio.h>

void main()
{
    FILE *fp = fopen("data.bin", "w+b");
    int num = 1234;
    fwrite(&num, sizeof(int), 1, fp);
    fseek(fp, 0, SEEK_SET);
    // int read;
    // fread(&read, sizeof(int), 1, fp);
    // printf("%d",read);
    // int read2;
    // int num_read = fread(&read2, sizeof(int), 1, fp);
    // printf("%d",num_read);
    int read;
    fscanf(fp, "%d", read);
    printf("%d", read);
}