#include <stdio.h>



struct A {
    float x;
    int y;
};

int main() {

    struct A a = {2.3, 20};

    int x = 5;
    
    // int được chuyển sang float
    float result = a.x + x;

    printf("Result: %.2f\n", result); // Output: 7.30
    return 0;
}
