#include <stdio.h>
#include "mylib.h"
#include "mylib2.h"

int main() {
    int a = 10, b = 5;
    printf("Addition: %d\n", add(a, b));
    printf("Subtraction: %d\n", subtract(a, b));
    return 0;
}
