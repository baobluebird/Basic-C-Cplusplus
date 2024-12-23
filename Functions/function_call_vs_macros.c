#include <stdio.h>
#include <time.h>

#define SQUARE_MACRO(x) ((x) * (x))  
int square_func(int x) {  
    return x * x;
}

int main() {
    int i;
    clock_t start, end;

    // Macro
    start = clock();
    for (i = 0; i < 10000000; i++) {
        int result = SQUARE_MACRO(i); 
    }
    end = clock();
    printf("Macro Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Function Call
    start = clock();
    for (i = 0; i < 10000000; i++) {
        int result = square_func(i);  
    }
    end = clock();
    printf("Function Call Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
