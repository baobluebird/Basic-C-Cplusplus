#include <stdio.h>

void main()
{
    FILE *fp = fopen("data.bin", "wb");
    int num = 1234;
    fwrite(&num, sizeof(int), 1, fp);
}