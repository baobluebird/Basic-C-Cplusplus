#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX 100

typedef struct Node {
    uint16_t data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    uint16_t array[MAX];
    uint16_t size;
} ArrayList;

void InitArray(ArrayList *list) {
    list->head = NULL;
    list->size = 0;
    printf("Array and linked list initialized.\n");
}

void AddElement(ArrayList *list, uint16_t value) {
    if (list->size >= MAX) {
        printf("Array is full. Cannot add more elements.\n");
        return;
    }
    
    list->array[list->size] = value;
    Node *newNode = (Node *)&list->array[list->size];
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;

    printf("Added %u to the list. Size: %u\n", value, list->size);
}

void DelElement(ArrayList *list, uint16_t value) {
    Node *current = list->head;
    Node *prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            printf("Deleted %u from the list.\n", value);
            list->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Value %u not found. No deletion.\n", value);
}

void Sort(ArrayList *list) {
    Node *i, *j;
    uint16_t temp;

    for (i = list->head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted in ascending order.\n");
}

int Search(ArrayList *list, uint16_t value) {
    Node *current = list->head;
    uint16_t index = 0;

    while (current != NULL) {
        if (current->data == value) {
            printf("Value %u found at position %u.\n", value, index);
            return index;
        }
        current = current->next;
        index++;
    }
    printf("Value %u not found in the list.\n", value);
    return -1;
}

void PrintList(ArrayList *list) {
    Node *current = list->head;
    printf("List elements: ");
    while (current != NULL) {
        printf("%u ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    ArrayList list;
    InitArray(&list);

    AddElement(&list, 10);
    AddElement(&list, 30);
    AddElement(&list, 20);
    AddElement(&list, 40);

    PrintList(&list);

    Sort(&list);
    PrintList(&list);

    Search(&list, 20);
    Search(&list, 100);

    DelElement(&list, 30);
    PrintList(&list);

    return 0;
}
