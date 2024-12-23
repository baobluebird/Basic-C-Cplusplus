#include <stdio.h>
#define Combine(x, y) x ## y

int main() {
    int xy = 10;
    // Combine 'x' and 'y' to get 'xy'
    printf("Value of xy: %d\n", Combine(x, y));
    return 0;
}
