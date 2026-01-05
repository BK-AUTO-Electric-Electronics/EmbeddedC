#include <stdio.h>
#include "bitmask_utils.h"
#include "function_handler.h"
#include "error_handler.h"

void engine_on(Module *m) {
    set_status(&m->status.status, STATUS_ON);
    printf("Engine ON\n");
}

void engine_off(Module *m) {
    clear_status(&m->status.status, STATUS_ON);
    printf("Engine OFF\n");
}

void engine_check(Module *m) {
    printf("\n=== Checking Engine ===\n");
    if(check_status(m->status.status, STATUS_ON) != 0){
        printf("ENGINE ON \n");
    }
    else{
        printf("ENGINE OFF \n");
    }
    warning(m);
}

void abs_on(Module *m) {
    set_status(&m->status.status, STATUS_ON);
    printf("ABS ON\n");
}

void abs_off(Module *m) {
    clear_status(&m->status.status, STATUS_ON);
    printf("ABS OFF\n");
}

void abs_check(Module *m) {
    printf("\n=== Checking ABS ===\n");
    if(check_status(m->status.status, STATUS_ON) != 0){
        printf("ABS ON \n");
    }
    else{
        printf("ABS OFF \n");
    }
    warning(m);
}
