#include <stdio.h>

int main() {
    FILE *fp = fopen("output.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    int age = 25;
    float salary = 50000.5;
    //fprintf(fp, "Age: %d\nSalary: %.2f\n", age, salary);
    printf("%d",(fprintf(fp, "Age: %d\nSalary: %.2f\n", age, salary)));
    fclose(fp);
    return 0;
}
