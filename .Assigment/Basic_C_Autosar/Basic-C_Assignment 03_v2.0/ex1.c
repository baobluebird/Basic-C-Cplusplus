#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX 100

typedef struct {
    uint16_t *address;
    uint16_t capacity;
    uint16_t size;
} Array;

void InitArray(Array *arr, uint16_t capacity) {
    arr->address = (uint16_t *)malloc(capacity * sizeof(uint16_t));
    if (arr->address != NULL) {
        arr->capacity = capacity;
        arr->size = 0;
        printf("Array initialized with capacity %u.\n", capacity);
    } else {
        printf("Memory allocation failed.\n");
        arr->capacity = 0;
        arr->size = 0;
    }
}

void AddElement(Array *arr, uint16_t value) {
    if (arr->size < arr->capacity) {
        arr->address[arr->size] = value;
        arr->size++;
        printf("Added %u to the array. Size: %u\n", value, arr->size);
    } else {
        printf("Array is full. Cannot add more elements.\n");
    }
}

void DelElement(Array *arr, uint16_t index) {
    if (index >= arr->size) {
        printf("Invalid index. No element deleted.\n");
        return;
    }
    for (uint16_t i = index; i < arr->size - 1; i++) {
        arr->address[i] = arr->address[i + 1];
    }
    arr->size--;
    printf("Element at index %u deleted. New size: %u\n", index, arr->size);
}

void Sort(Array *arr) {
    for (uint16_t i = 0; i < arr->size - 1; i++) {
        for (uint16_t j = i + 1; j < arr->size; j++) {
            if (arr->address[i] > arr->address[j]) {
                uint16_t temp = arr->address[i];
                arr->address[i] = arr->address[j];
                arr->address[j] = temp;
            }
        }
    }
    printf("Array sorted in ascending order.\n");
}

int Search(Array *arr, uint16_t value) {
    for (uint16_t i = 0; i < arr->size; i++) {
        if (arr->address[i] == value) {
            printf("Value %u found at index %u.\n", value, i);
            return i;
        }
    }
    printf("Value %u not found in the array.\n", value);
    return -1;
}

void FreeArray(Array *arr) {
    if (arr->address != NULL) {
        free(arr->address);
        arr->address = NULL;
        arr->capacity = 0;
        arr->size = 0;
        printf("Array memory freed.\n");
    }
}

int main() {
    Array arr;
    InitArray(&arr, MAX);

    AddElement(&arr, 10);
    AddElement(&arr, 20);
    AddElement(&arr, 40);
    AddElement(&arr, 30);

    printf("\nArray before sorting:\n");
    for (uint16_t i = 0; i < arr.size; i++) {
        printf("%u ", arr.address[i]);
    }
    printf("\n");

    Sort(&arr);

    printf("\nArray after sorting:\n");
    for (uint16_t i = 0; i < arr.size; i++) {
        printf("%u ", arr.address[i]);
    }
    printf("\n");

    Search(&arr, 20);
    Search(&arr, 100);

    printf("\nDelete 20 in index 1:\n");
    DelElement(&arr, 1);

    printf("\nArray after deletion:\n");
    for (uint16_t i = 0; i < arr.size; i++) {
        printf("%u ", arr.address[i]);
    }
    printf("\n");

    FreeArray(&arr);

    return 0;
}
