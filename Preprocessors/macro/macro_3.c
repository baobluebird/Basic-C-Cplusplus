#include <stdio.h>
#define SQUARE(x)(x * x)

int main() {
    printf("%d\n", SQUARE(1 + 2)); // Macro called with 1+2*1+2 results in missing parentheses
    return 0;
}
