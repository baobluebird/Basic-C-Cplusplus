#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    //use malloc, calloc
    struct Person *p1;
    p1 = (struct Person*) calloc(10, sizeof(struct Person));  // Cấp phát bộ nhớ động

    //strcpy(p1[0].name, "John");
    p1->age = 25;

    //printf("Name: %s, Age: %d\n", p1[0].name, p1->age);

    printf("Address pointer p1: %p\n", p1);

    printf("Address p1[0].age: %p\n", (void*)&p1[0].age);

    //use object
    struct Person people;

    struct Person *p2;
    p2 = &people;

    strcpy(p2->name, "Bao");
    p2->age = 20;

    printf("Name: %s, Age: %d\n", people.name, p2->age);


    free(p1);  // Giải phóng bộ nhớ sau khi sử dụng
    return 0;
}
