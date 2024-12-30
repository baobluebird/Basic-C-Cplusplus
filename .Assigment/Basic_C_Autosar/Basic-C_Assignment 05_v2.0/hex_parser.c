#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h> 

#define START_CODE ':'

// Error codes
typedef enum {
    NO_ERROR,
    FORMAT_ERROR,
    CHECKSUM_ERROR,
    BYTE_COUNT_ERROR,
    EOF_MISSING_ERROR
} hex_error_t;

// Calculate checksum
uint8_t calculate_checksum(char *record) {
    uint8_t sum = 0;
    int length = (strlen(record) - 11) / 2;  // Exclude checksum byte and ':'

    printf("Processing Record: %s\n", record);

    for (int i = 0; i < length + 4; i++) {  // Sum byte count + address + type + data
        char byte_string[3];
        byte_string[0] = record[i * 2 + 1];
        byte_string[1] = record[i * 2 + 2];
        byte_string[2] = '\0';
        uint8_t byte_value = (uint8_t)strtol(byte_string, NULL, 16);
        sum += byte_value;
        printf("Byte: %s, Value: %02X, Running Sum: %02X\n", byte_string, byte_value, sum);
    }

    // Do NOT include the checksum byte in the calculation
    uint8_t checksum = (uint8_t)(~sum + 1);  // Two's complement
    printf("Calculated Checksum: %02X\n", checksum);

    return checksum;
}




// Parse Intel HEX record
hex_error_t parse_record(char *record, uint16_t *segment_address, uint16_t *absolute_address) {
    int byte_count, address, record_type, checksum;
    int calculated_checksum;

    // Trim trailing characters
    int len = strlen(record);
    while (len > 0 && (record[len - 1] == '\n' || record[len - 1] == '\r')) {
        record[--len] = '\0';
    }

    if (record[0] != START_CODE) {
        return FORMAT_ERROR;
    }

    sscanf(record + 1, "%2x%4x%2x", &byte_count, &address, &record_type);

    int data_length = (strlen(record) - 11) / 2;  // Exclude checksum

    if (byte_count != data_length) {
        return BYTE_COUNT_ERROR;
    }

    calculated_checksum = calculate_checksum(record);

    sscanf(record + len - 2, "%2x", &checksum);  // Read checksum from the last 2 characters

    printf("Expected Checksum: %02X\n", checksum);

    if (calculated_checksum != checksum) {
        printf("Checksum mismatch! Calculated: %02X, Expected: %02X\n", calculated_checksum, checksum);
        return CHECKSUM_ERROR;
    }

    switch (record_type) {
        case 0x00:  // Data Record
            *absolute_address = *segment_address + address;
            break;
        case 0x02:  // Extended Segment Address Record
            *segment_address = address << 4;
            break;
        case 0x01:  // End Of File Record
            return NO_ERROR;
        default:
            return FORMAT_ERROR;
    }
    return NO_ERROR;
}

