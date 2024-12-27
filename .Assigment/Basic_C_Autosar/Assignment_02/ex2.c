#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>  

bool allocate10Bytes(uint8_t *outPtr) {
    if (outPtr == NULL) {
        return false;
    }
    
    uint8_t *ptr = (uint8_t *)malloc(10 * sizeof(uint8_t));
    
    if (ptr == NULL) {
        return false;  
    }
    
    *outPtr = *ptr;
    
    return true;
}
