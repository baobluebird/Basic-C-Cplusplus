#include <stdio.h>
#include <string.h>
#include "hex_parser.c"
#include <stdlib.h> 

#define MAX_LINE_LENGTH 256

void handle_error(hex_error_t error) {
    switch (error) {
        case FORMAT_ERROR:
            printf("File has an invalid format.\n");
            break;
        case CHECKSUM_ERROR:
            printf("Checksum error detected.\n");
            break;
        case BYTE_COUNT_ERROR:
            printf("Byte count error detected.\n");
            break;
        case EOF_MISSING_ERROR:
            printf("Missing End-Of-File (EOF) record.\n");
            break;
        case NO_ERROR:
            break;
        default:
            printf("Unknown error.\n");
            break;
    }
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    uint16_t segment_address = 0;
    uint16_t absolute_address = 0;
    int eof_found = 0;

    file = fopen("hexfile.hex", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        hex_error_t error = parse_record(line, &segment_address, &absolute_address);
        if (error != NO_ERROR) {
            handle_error(error);
            fclose(file);
            return 1;
        }

        if (line[7] == '0' && line[8] == '1') {
            eof_found = 1;
            break;
        }

        printf("Absolute Address: %04X, Data: ", absolute_address);
        for (int i = 9; i < strlen(line) - 3; i += 2) {
            printf("%c%c ", line[i], line[i + 1]);
        }
        printf("\n");
    }

    if (!eof_found) {
        printf("File is invalid: End Of File (EOF) record is missing.\n");
    } else {
        printf("File successfully parsed.\n");
    }

    fclose(file);
    return 0;
}
