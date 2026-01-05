#include "error_handler.h"
#include "module_manager.h"
#include <stdio.h>

jmp_buf safe_point;

void safe_reset(void) {
    for (int i = 0; i < module_count; i++) {
        module_list[i].status.raw = 0; 
    }
    printf(" Quay ve SAFE MODE \n");
}
