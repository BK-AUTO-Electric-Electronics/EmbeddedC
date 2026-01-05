#ifndef BITMASK_UTILS_H
#define BITMASK_UTILS_H
#include<stdint.h>
void set_bit(uint8_t *status, uint8_t flag);
void clear_bit(uint8_t *status, uint8_t flag);
void check_bit(uint8_t status, uint8_t flag);
#endif