#define STATUS_ON        (1 << 0)  // Module đang bật
#define STATUS_ERROR     (1 << 1)  // Module gặp lỗi
#define STATUS_WARNING   (1 << 2)  // Cảnh báo lỗi
#include "bitmask_utils.h"
#include<stdint.h>
void set_bit(uint8_t *status, uint8_t status_bit) {
     *status |= status_bit;
}
void clear_bit(uint8_t *status, uint8_t status_bit) {
    *status  &= ~status_bit;
}
void check_bit(uint8_t status, uint8_t status_bit){
    return (status & status_bit);
}

