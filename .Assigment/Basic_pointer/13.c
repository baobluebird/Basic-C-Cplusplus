#include<stdio.h> 
int f(int x, int *py, int **ppz) 
{ 
  int y, z; 
  **ppz += 1; //c = 5
   z  = **ppz; //z = 5
  *py += 2; // c = 5 + 2 = 7
   y = *py; //y = 7
   x += 3; //x = 4 + 3 = 7
   return x + y + z; 
} 
   
int main() 
{ 
   int c, *b, **a; 
   c = 4; 
   b = &c; // b is the address of c
   a = &b; // a is the address of b
   printf("%d ", f(c, b, a)); //7 7 5
   return 0;
}
