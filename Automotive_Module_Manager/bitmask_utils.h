#ifndef BITMASK_UTILS_H
#define BITMASK_UTILS_H

#include <stdint.h>

#define STATUS_OFF 0 // 000
#define STATUS_ON (1 << 0) // 001
#define STATUS_ERROR (1 << 1) //010
#define STATUS_WARNING (1 << 2) // 100

void set_status(uint8_t *status, uint8_t flag);
void clear_status(uint8_t *status, uint8_t flag);
int check_status(uint8_t status, uint8_t flag);

#endif