#include <stdio.h>
#define PI 3.14
#define MAX_USERS 100
#define FILENAME "data.txt"

int main() {
    int x = 2;
    float area = PI * x * x;
    printf("Area: %f\n", area);
    int current_users = 50;
    if (current_users > MAX_USERS) {
        printf("User limit exceeded. Maximum allowed users: %d\n", MAX_USERS);
    } else {
        printf("Current users: %d. Maximum allowed users: %d\n", current_users, MAX_USERS);
    }

    printf("File to open: %s\n", FILENAME);
    return 0;
}
