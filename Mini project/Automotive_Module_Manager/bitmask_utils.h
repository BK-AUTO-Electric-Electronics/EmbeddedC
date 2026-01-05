#ifndef BITMASK_UTILS_H
#define BITMASK_UTILS_H

#include <stdint.h>


#define STATUS_ON        (1 << 0)
#define STATUS_LOI       (1 << 1)
#define STATUS_CANHBAO   (1 << 2)


typedef union {
    uint8_t raw;
    struct {
        uint8_t on       : 1;
        uint8_t loi      : 1;
        uint8_t canhbao  : 1;
        uint8_t res      : 5;
    } bit;
} ModuleStatus;


void status_set(ModuleStatus *s, uint8_t mask);
void status_clear(ModuleStatus *s, uint8_t mask);
uint8_t status_check(ModuleStatus s, uint8_t mask);

#endif
