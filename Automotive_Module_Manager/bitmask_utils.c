#include "bitmask_utils.h"

void set_status(uint8_t *status, uint8_t flag) { 
    *status |= flag;
}

void clear_status(uint8_t *status, uint8_t flag) {
    *status &= ~flag;    
}

int check_status(uint8_t status, uint8_t flag) {
    return (status & flag) != 0;
}