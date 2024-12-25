#include <stdio.h>

int main() {
    FILE *fp = fopen("output.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    int age;
    float salary;
    
    fscanf(fp, "Age: %d\nSalary: %f\n", &age, &salary);

    printf("Read from file:\nAge: %d\nSalary: %.2f\n", age, salary);

    fclose(fp);
    return 0;
}
