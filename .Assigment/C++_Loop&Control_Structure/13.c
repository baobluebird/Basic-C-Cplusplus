#include <stdio.h>
int main()
{
    int i = 3;
    switch(i)
    {
        printf("Outside ");
        case 1: printf("Geeks");
            break;
        case 2: printf("Quiz");
            break;
        default: printf("GeeksQuiz");
    }
    return 0;
}