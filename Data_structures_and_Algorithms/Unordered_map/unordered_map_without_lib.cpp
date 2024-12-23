#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List node
struct node {
    char* key; // key is string
    char* value; // value is also string
    struct node* next;
};

// Constructor-like function to initialize a node
void setNode(struct node* node, const char* key, const char* value) {
    node->key = strdup(key); // Allocate and copy key
    node->value = strdup(value); // Allocate and copy value
    node->next = NULL;
}

// HashMap structure
struct hashMap {
    int numOfElements, capacity; // Number of elements and capacity
    struct node** arr; // Array of linked list pointers
};

// Constructor-like function to initialize hashMap
void initializeHashMap(struct hashMap* mp) {
    mp->capacity = 100; // Default capacity
    mp->numOfElements = 0;
    mp->arr = (struct node**)calloc(mp->capacity, sizeof(struct node*)); // Allocate and zero-initialize array
}

// Hash function to calculate bucket index
int hashFunction(struct hashMap* mp, const char* key) {
    int sum = 0, factor = 31;
    for (size_t i = 0; i < strlen(key); i++) {
        sum = (sum + ((int)key[i] * factor)) % mp->capacity;
        factor = (factor * 31) % 0x7FFFFFFF; // Use large prime for safety
    }
    return sum;
}

// Insert key-value pair into the hashMap
void insert(struct hashMap* mp, const char* key, const char* value) {
    int bucketIndex = hashFunction(mp, key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    setNode(newNode, key, value);

    if (mp->arr[bucketIndex] == NULL) {
        mp->arr[bucketIndex] = newNode;
    } else {
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
    mp->numOfElements++;
}

// Delete key from hashMap
void deleteKey(struct hashMap* mp, const char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* prevNode = NULL;
    struct node* currNode = mp->arr[bucketIndex];

    while (currNode != NULL) {
        if (strcmp(currNode->key, key) == 0) {
            if (prevNode == NULL) { // Head node
                mp->arr[bucketIndex] = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            mp->numOfElements--;
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// Search for a key in the hashMap
const char* search(struct hashMap* mp, const char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* bucketHead = mp->arr[bucketIndex];

    while (bucketHead != NULL) {
        if (strcmp(bucketHead->key, key) == 0) {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }
    return "Oops! No data found.";
}

// Free the hashMap and all its elements
void freeHashMap(struct hashMap* mp) {
    for (int i = 0; i < mp->capacity; i++) {
        struct node* currNode = mp->arr[i];
        while (currNode != NULL) {
            struct node* nextNode = currNode->next;
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            currNode = nextNode;
        }
    }
    free(mp->arr);
    free(mp);
}

// Driver code
int main() {
    struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    initializeHashMap(mp);

    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "GeeksforGeeks");
    insert(mp, "decentBoy", "Mayank");
    insert(mp, "decentBoy", "Mayank123123");

    printf("%s\n", search(mp, "elite_Programmer"));
    printf("%s\n", search(mp, "Yogaholic"));
    printf("%s\n", search(mp, "pluto14"));
    printf("%s\n", search(mp, "decentBoy"));
    printf("%s\n", search(mp, "GFG"));

    printf("%s\n", search(mp, "randomKey"));

    printf("\nAfter deletion:\n");
    deleteKey(mp, "decentBoy");
    printf("%s\n", search(mp, "decentBoy"));

    freeHashMap(mp);
    return 0;
}
