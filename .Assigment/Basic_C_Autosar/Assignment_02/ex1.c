#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    uint16_t *aptr = NULL;
    uint16_t *bptr = NULL;
    int n;

    printf("Enter the number of elements (< 255): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 255) {
        printf("Invalid input. Please enter a number between 1 and 254.\n");
        return 1;
    }

    aptr = (uint16_t*) malloc(n * sizeof(uint16_t));

    if (aptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d positive integers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%hu", &aptr[i]);
    }

    printf("\nElements in reverse order (with addresses):\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("0x%llx : %hu\n", (unsigned long long)(uintptr_t)&aptr[i], aptr[i]);
    }

    bptr = aptr;
    for (int i = 1; i < n; i++) {
        if (aptr[i] > *bptr) {
            bptr = &aptr[i];
        }
    }

    printf("\nLargest element: %hu at address 0x%llx\n", *bptr, (unsigned long long)(uintptr_t)bptr);

    free(aptr);
    printf("\nMemory has been freed.\n");

    return 0;
}
