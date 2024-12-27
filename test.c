#include <stdio.h>
int var = 20;
int main()
{
    int a = 3;
    int *p = &a;
    int y = a /*p/p point x */;
    printf("%d",y);
}