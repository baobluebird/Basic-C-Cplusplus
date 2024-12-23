#include <stdio.h>
#include "extern1.h"
extern int count; // Khai báo extern biến count

void printCount() {
    printf("Value of count: %d\n", count);
}

int main(){
    printCount();
    increment();
    printCount();
    return 0;
}