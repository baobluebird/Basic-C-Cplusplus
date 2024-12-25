#include<stdio.h>
int main()
{
    int i = 0;
    for (printf("1st\n"); i < 2 && printf("2nd\n"); ++i && printf("3rd\n"))
    {
        printf("*\n");
    }
    return 0;
}