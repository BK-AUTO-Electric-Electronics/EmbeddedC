#include "bitmask_utils.h"

void set_status(unsigned char *status, unsigned char flag) {
    if (status) *status |= flag;
}

void clear_status(unsigned char *status, unsigned char flag) {
    if (status) *status &= ~flag;
}

int is_status_set(unsigned char status, unsigned char flag) {
    return (status & flag) != 0;
}