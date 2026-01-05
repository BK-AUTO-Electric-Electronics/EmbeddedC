#include <stdio.h>
#include "error_handler.h"

jmp_buf save_state;

void handle_critical_error(const char* module_name) {
    printf("\n[ALERT] Critical Error detected in: %s\n", module_name);
    longjmp(save_state, 1);
}