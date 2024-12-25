#include<stdio.h>
void fun(int arr[])
{
  int i;
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  for (i = 0; i < arr_size; i++)
      printf("%d ", arr[i]);
}
 
int main()
{
  int i;
  int arr[4] = {10, 20 ,30, 40};
  int *ptr = arr;
  int a = 5;
  int *ptr2 = &a;
  printf("first element of array: %d\n", *ptr);
  printf("first element of array: %d\n", ptr2[2]);
  //fun(arr);
  return 0;
} 