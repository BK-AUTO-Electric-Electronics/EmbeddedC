#ifndef BITMASK_UTILS_H
#define BITMASK_UTILS_H

#define STATUS_ON 1 << 0
#define STATUS_ERROR 1 << 1
#define STATUS_WARNING 1 << 2

void set_status(unsigned char *status, unsigned char flag);
void clear_status(unsigned char *status, unsigned char flag);
int check_status(unsigned char status, unsigned char flag);

#endif