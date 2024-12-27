#include <stdio.h>
#include <stdint.h>

void absoluteValue(uint8_t *data) {
    uint8_t a = data[0];
    uint8_t b = data[1];

    if (a > b) {
        data[2] = a - b;
    } else {
        data[2] = b - a;
    }
}

int main() {
    uint8_t data[3];  

    char choice;
    do {
        printf("Enter two 8-bit positive integers (0-255):\n");
        printf("a: ");
        scanf("%hhu", &data[0]);
        printf("b: ");
        scanf("%hhu", &data[1]);

        absoluteValue(data);

        printf("\na = %u, b = %u\n", data[0], data[1]);
        printf("Absolute value of difference = %u\n\n", data[2]);

        printf("Do you want to calculate again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
