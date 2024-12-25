#include <stdio.h>

void callbackFunction(int n) {
    printf("Callback called with %d\n", n);
}

void executeCallback(void (*callback)(int), int value) {
    callback(value);
}

int main() {
    executeCallback(callbackFunction, 10);
    return 0;
}
// Output: Callback called with 10
