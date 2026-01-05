#include "module_manager.h"
#include "function_handler.h"
#include "bitmask_utils.h"
#include "error_handler.h"
#include <stdio.h>

void turn_on_module(Module *m) {
    set_status(&m->status, STATUS_ON);
    clear_status(&m->status, STATUS_ERROR | STATUS_WARNING);
    printf("ON\n");
}

void turn_off_module(Module *m) {
    clear_status(&m->status, STATUS_ON);
    printf("OFF\n");
}

void check_module(Module *m) {
    if (check_status(m->status, STATUS_ERROR)) {
        printf("ERROR\n");
        throw_error();
    }
    else if (check_status(m->status, STATUS_WARNING)) {
        printf("WARNING\n");
    }
    else {
        printf("OK\n");
    }
}

