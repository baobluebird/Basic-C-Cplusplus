#include <stdio.h>

int main() {
    int a = 5;
    int *ptr = &a;
    
    printf("Size of int: %zu bytes\n", sizeof(a));  // Size of int
    printf("Size of pointer: %zu bytes\n", sizeof(ptr));  // Size of pointer

    return 0;
}
