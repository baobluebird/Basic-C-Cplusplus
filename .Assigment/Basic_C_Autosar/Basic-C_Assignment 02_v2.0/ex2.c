#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
bool allocate10Bytes(uint8_t* outPtr) {
  uint8_t** outPtr1 = (uint8_t**)(outPtr);
  *outPtr1 = malloc(10 * sizeof(uint8_t));

  if (*outPtr1 == NULL) {
    return false;
  }

  return true;
}

int main(void) {
  uint8_t* p = NULL;

  bool success = allocate10Bytes((uint8_t*)&p);
  printf("%d",success);
  if (success) free(p);
  return 0;
}