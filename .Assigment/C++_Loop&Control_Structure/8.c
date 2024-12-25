#include <stdio.h>
int main()
{
    int c = 5, no = 10;
    do {
        no /= c;
    } while (c--);

    printf("%d\n", no);  // In giá trị cuối cùng của `no`
    return 0;
}
