#include "bitmask_utils.h"

void set_status(unsigned char *status, unsigned char flag) {
    *status |= flag;
}

void clear_status(unsigned char *status, unsigned char flag) {
    *status &= ~flag;
}

int check_status(unsigned char status, unsigned char flag) {
    return(status & flag) ;
}