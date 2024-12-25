#include <stdio.h>

void main()
{
    char inchar = 'A';
    switch (inchar)
    {
    case 'A':
        printf("choice A n");
    case 'B':
        printf("choice B ");
    case 'C':
    case 'D':
    case 'E':
    default:
        printf("No Choice");
    }
}