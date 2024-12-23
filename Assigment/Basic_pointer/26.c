# include <stdio.h>
# define swap1(a, b) tmp = a; a = b; b = tmp
void swap2 ( int a, int b)
{
        int tmp;
        tmp = a; a = b; b = tmp;
 }
void swap3 (int*a, int*b)
{
        int tmp;
        tmp = *a;//tmp = 5 
        *a = *b; //a = 4
         *b = tmp;//b = 5
}
int main ()
{
        int num1 = 5, num2 = 4, tmp;
        if (num1 < num2) {swap1 (num1, num2);}
        if (num1 < num2) {swap2 (num1 + 1, num2);}
        if (num1 >= num2) {swap3 (&num1, &num2);}
        printf ("%d, %d", num1, num2);
}