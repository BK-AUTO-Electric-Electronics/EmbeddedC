#include <stdio.h>
#include "function_handler.h"
#include "module_manager.h"
#include "bitmask_utils.h"

void module_on(Module *m) {
    set_bit(&m->status, STATUS_ON);
    printf("[%s] ON\n", m->name);
}

void module_off(Module *m) {
    clear_bit(&m->status, STATUS_ON);
    printf("[%s] OFF\n", m->name);
}

void module_fault(Module *m) {
    set_bit(&m->status, STATUS_ERROR);
    printf("[%s] ERROR!\n", m->name);
}

void module_check(Module *m) {
    printf("[%s] STATUS: ", m->name);

    if (check_bit(m->status, STATUS_ON))
        printf("ON ");

    if (check_bit(m->status, STATUS_ERROR))
        printf("ERROR ");

    if (check_bit(m->status, STATUS_WARNING))
        printf("WARNING ");

    printf("\n");
}