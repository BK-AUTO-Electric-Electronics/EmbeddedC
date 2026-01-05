#ifndef BITMASK_UTILS_H
#define BITMASK_UTILS_H

#include <stdint.h>
typedef uint8_t status_t;

typedef enum{
   STATUS_ON = (1U << 0),
   STATUS_ERROR = (1U << 1),
   STATUS_WARNING  = (1U << 2)
} status_flag_t;


void set_status(uint8_t *status, uint8_t flag);
void clear_status(uint8_t *status, uint8_t flag) ;
int check_status(uint8_t status, uint8_t flag) ;
#endif