#include "bitmask_utils.h"

void status_set(ModuleStatus *s, uint8_t mask) {
    s->raw |= mask;
}

void status_clear(ModuleStatus *s, uint8_t mask) {
    s->raw &= (uint8_t)~mask;
}

uint8_t status_check(ModuleStatus s, uint8_t mask) {
    return (uint8_t)(s.raw & mask);
}
