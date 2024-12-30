#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

typedef enum _statetype {
    CORRECT,
    CHAR_INVALID,
    LENGHT_INVALID
} status_enum_t;

typedef void (*func)(status_enum_t);

static func errorCallback = NULL;

void RegisterCallback(func func_add) {
    errorCallback = func_add;
}

void Check_Account(char *ptr, uint8_t length) {
    if (length > 10) {
        if (errorCallback != NULL) {
            errorCallback(LENGHT_INVALID);
        }
        return;
    }

    for (uint8_t i = 0; i < length; i++) {
        if (!isalnum(ptr[i])) {
            if (errorCallback != NULL) {
                errorCallback(CHAR_INVALID);
            }
            return;
        }
    }

    if (errorCallback != NULL) {
        errorCallback(CORRECT);
    }
}
