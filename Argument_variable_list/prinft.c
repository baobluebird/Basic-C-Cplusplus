#include <stdio.h>
#include <stdarg.h>
#line 100 "generated_code.c"
void printNumbers(int num, ...) {
    va_list args;
    va_start(args, num);

    for (int i = 0; i < num; i++) {
        printf("%d ", va_arg(args, int));  // In mỗi số
    }

    va_end(args);
}

int main() {
    printNumbers(3, 1, 2, 3);   // In 3 số
    printf("\n");
    printNumbers(5, 10, 20, 30, 40, 50);  // In 5 số
    return 0;
}
