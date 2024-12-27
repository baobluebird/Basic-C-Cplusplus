#include <stdio.h>

int main() {
    FILE *fp = fopen("example.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
   // int b = fseek(fp, 0 , SEEK_END);
    //printf("%d\n", b);
    long position1 = ftell(fp);
    printf("Current position: %ld\n", position1);

    char a[100];
    fgets(a, sizeof(a), fp);  
    printf("%s", a);
    fgets(a, sizeof(a), fp);  
    printf("%s", a);
    long position2 = ftell(fp);
    printf("Current position: %ld\n", position2);
    fclose(fp);
    return 0;
}
