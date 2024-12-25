#include<stdio.h>
int main()
{
    double arr[] = {10, 20, 30, 40, 50, 60};
    double *ptr1 = arr;
    double *ptr2 = arr + 5;
    printf("Number of elements between two pointer are: %d.",  (ptr2 - ptr1));
    printf("Number of bytes between two pointers are: %d",  (int*)ptr2 - (int*) ptr1);
    return 0;
}

