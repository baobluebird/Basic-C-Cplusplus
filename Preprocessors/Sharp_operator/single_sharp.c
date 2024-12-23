#include <stdio.h>
#define TO_STRING(x) #x

int main() {
    printf("String from macro: %s\n", TO_STRING(Hello World!));
    // converts all characters, including spaces, into a string.
    return 0;
}