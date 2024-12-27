#include <stdio.h>
#include <stdbool.h>
#include "array_manager.h"

void print_menu() {
    printf("\nInteger Array Management Program\n");
    printf("Enter 'c' to create/reset the array.\n");
    printf("Enter 'p' to print the array.\n");
    printf("Enter 'i' to insert an element at a specified position.\n");
    printf("Enter 'd' to delete an element at a specified position.\n");
    printf("Enter 's' to sort the array in ascending order.\n");
    printf("Enter 'x' to sort the array in descending order.\n");
    printf("Enter 't' to search for a specific number.\n");
    printf("Enter 'e' to exit the program.\n");
}

int main() {
    char choice;
    do {
        print_menu();
        printf("Your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'c':
                create_array();
                break;
            case 'p':
                print_array();
                break;
            case 'i': {
                int position, value;
                printf("Enter position and value to insert: ");
                if (scanf("%d %d", &position, &value) != 2) {
                    printf("Invalid input.\n");
                    break;
                }
                insert_element(position, value);
                break;
            }
            case 'd': {
                int position;
                printf("Enter position to delete: ");
                if (scanf("%d", &position) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                delete_element(position);
                break;
            }
            case 's':
                sort_array_ascending();
                break;
            case 'x':
                sort_array_descending();
                break;
            case 't': {
                int value;
                printf("Enter the number to search: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                if (find_element(value)) {
                    printf("%d is in the array.\n", value);
                } else {
                    printf("%d is not in the array.\n", value);
                }
                break;
            }
            case 'e':
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 'e');

    return 0;
}
