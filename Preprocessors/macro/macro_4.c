#include <stdio.h>
#define SQUARE(x)((x) * (x))

int main() {
    printf("%d\n", SQUARE(1 + 2)); // (1+2)*(1+2)
    return 0;
}
