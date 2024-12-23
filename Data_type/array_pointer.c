// #include <stdio.h>

// int main()
// {
//     int arr[5] = {1, 2, 3, 4, 5};
//     int *ptr = arr;

//     printf("%d ", *(ptr + 1)); 
//     printf("%d ", ptr[1]); 

//     printf("%d ", arr[1]);   
//     printf("%d ", *(arr + 1));

//     return 0;
// }

#include <stdio.h>

void modifyArray(int *arr, int size) {
    int *ptr = arr;
    
    
    //arr[0] = 10;
   // arr[1] = 20;
   //*(arr + 2) = 30;
    ptr[0] = 10;
    *(ptr + 1) = 20;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    modifyArray(arr, 5);
    printf("%d\n", arr[0]);  // Output: 10
    printf("%d\n", arr[1]);  // Output: 20
    
    printf("%d\n", arr[2]);  // Output: 30
    return 0;
}
