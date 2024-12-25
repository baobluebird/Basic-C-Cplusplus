#include<stdio.h>
 
void swap (char *x, char *y)
{
    char *t = x;
    x = y;
    y = t;
}
 
int main()
{
    char *x = "AAAA";
    char *y = "BBBB";
    char *t;
    swap(x, y);
    printf("(%s, %s)", x, y);
    t = x;
    x = y;
    y = t;
    printf("\n(%s, %s)", x, y);
    return 0;
}
