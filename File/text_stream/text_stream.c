#include <stdio.h>

void main()
{
    FILE *fp = fopen("textfile.txt", "w");
    fprintf(fp, "Hello World\n");
    fprintf(fp, "Hello World");
}