#ifndef BITMASK_UTILS_H
#define BITMASK_UTILS_H

#define STATUS_ON        (1 << 0)  // 0x01
#define STATUS_ERROR     (1 << 1)  // 0x02
#define STATUS_WARNING   (1 << 2)  // 0x04

void set_status(unsigned char *status, unsigned char flag);
void clear_status(unsigned char *status, unsigned char flag);
int is_status_set(unsigned char status, unsigned char flag); // Kiểm tra bitmask

#endif