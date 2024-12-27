#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array_manager.h"

#define MAX_SIZE 100

static int array[MAX_SIZE];
static int size = 0;

void create_array() {
    size = 0;
    printf("Array has been created/reset.\n");
}

void print_array() {
    if (size == 0) {
        printf("The array is empty.\n");
        return;
    }
    printf("Current array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insert_element(int position, int value) {
    if (position < 0 || position > size || size >= MAX_SIZE) {
        printf("Invalid position or array is full.\n");
        return;
    }
    for (int i = size; i > position; i--) {
        array[i] = array[i - 1];
    }
    array[position] = value;
    size++;
    printf("Inserted %d at position %d.\n", value, position);
}

void delete_element(int position) {
    if (position < 0 || position >= size) {
        printf("No element at position %d.\n", position);
        return;
    }
    for (int i = position; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
    printf("Deleted element at position %d.\n", position);
}

void sort_array_ascending() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("Array sorted in ascending order.\n");
}

void sort_array_descending() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] < array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("Array sorted in descending order.\n");
}

bool find_element(int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return true;
        }
    }
    return false;
}
