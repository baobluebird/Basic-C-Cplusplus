#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    int n = 3; // Số lượng đối tượng muốn tạo
    struct Person *p1, *p2, *p3; // Các con trỏ trỏ đến từng đối tượng

    // Cấp phát bộ nhớ cho từng đối tượng riêng lẻ
    p1 = (struct Person*) malloc(sizeof(struct Person));
    p2 = (struct Person*) malloc(sizeof(struct Person));
    p3 = (struct Person*) malloc(sizeof(struct Person));

    if (p1 == NULL || p2 == NULL || p3 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Gán giá trị cho từng đối tượng
    strcpy(p1->name, "John");
    p1->age = 25;

    strcpy(p2->name, "Alice");
    p2->age = 30;

    strcpy(p3->name, "Bob");
    p3->age = 22;

    // In các đối tượng
    printf("Person 1: Name: %s, Age: %d\n", p1->name, p1->age);
    printf("Person 2: Name: %s, Age: %d\n", p2->name, p2->age);
    printf("Person 3: Name: %s, Age: %d\n", p3->name, p3->age);

    // Giải phóng bộ nhớ
    free(p1);
    free(p2);
    free(p3);

    return 0;
}
