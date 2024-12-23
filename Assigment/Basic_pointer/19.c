#include <stdio.h>
#define print(x) printf("%d ", x)
int x;
void Q(int z)
{
    z += x;
    print(z);// 7 + 5 = 12
}
void P(int *y)
{
    int x = *y + 2;
    Q(x);
    *y = x - 1;
    print(x);
}
main(void)
{
    x = 5;
    P(&x);
    print(x);
    
}
