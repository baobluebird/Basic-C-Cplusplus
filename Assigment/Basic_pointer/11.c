#include<stdio.h> 
void f(int *p, int *q) 
{ 
  p = q; 
  *p = 2; 
    printf("ham f: %p \n", p); 
} 
int i = 0, j = 1; 
int main() 
{ 
  f(&i, &j);
  int *ptr = &i;
  printf("ham main: %p \n", &i);  
  printf("ham main: %p \n", ptr);  
  printf("%d %d \n", i, j); 
  getchar(); 
  return 0; 
}