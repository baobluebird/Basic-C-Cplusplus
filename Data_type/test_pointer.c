#include <stdio.h>

int main() {
    int arr[4] = {10, 20 ,30, 40};
    int *ptr = arr;

    printf("Value at ptr = %p\n", ptr);
    printf("Dia chi phan tu thu 2 trong mang: %p\n", arr + 1);
    printf("Gia tri phan tu thu 2 trong mang: %d\n", *(arr + 1));


    char c[10] = "hello";
    char *p[10] = &c;
    printf("Dia chi cua mang: %s\n", (char)*p);

    return 0;
}