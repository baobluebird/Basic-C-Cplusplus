#include <stdio.h>
int fun(int arr[]) {
   arr = arr+1; 
   printf("%d ", arr[0]);
}
int main(void) {
   int arr[2] = {10, 20};
   fun(arr);
   printf("%d", arr[0]);
   return 0;
}