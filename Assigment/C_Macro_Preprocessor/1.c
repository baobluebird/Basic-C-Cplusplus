// #include <stdio.h>
// #define PRINT(i, limit) do{if (i++ < limit) { printf("GeeksQuizn"); continue; } }while(1);
 
// int main()
// {
//     PRINT(0, 3);
//     return 0;
// }

#include <stdio.h>

// Định nghĩa function-like macro
#define SQUARE(x) ((x) * (x))

int main() {
    int b = SQUARE(5);  // Truyền trực tiếp giá trị 5 vào macro
    printf("Square of 5 is %d\n", b);
    return 0;
}
