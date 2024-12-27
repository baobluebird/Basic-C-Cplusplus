#include <stdio.h>
#include <stdint.h>
#include "lib.c"

void ErrorHandler(status_enum_t status) {
    switch (status) {
        case CORRECT:
            printf("Account is valid.\n");
            break;
        case CHAR_INVALID:
            printf("CHAR_INVALID\n");
            break;
        case LENGHT_INVALID:
            printf("LENGHT_INVALID\n");
            break;
        default:
            printf("Unknown error.\n");
            break;
    }
}

int main() {
    char arr[20];
    uint8_t length;

    RegisterCallback(ErrorHandler);

    while (1) {
        printf("Enter account (max 10 characters, 'exit' to quit): ");
        scanf("%s", arr);

        if (strcmp(arr, "exit") == 0) {
            break;
        }

        length = strlen(arr);
        Check_Account(arr, length);
    }

    return 0;
}
