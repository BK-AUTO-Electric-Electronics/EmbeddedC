#include<stdio.h>
#include<setjmp.h>
#include "function_handler.h"
#include "error_handler.h"
#include "module_manager.h"

int main() {
    if(setjmp(error_jump)) {
        printf("Hệ thống gặp lỗi");
    }
    add_module(1, "ENGINE");
    add_module(2, "ABS_BRAKE");
    Module *engine= get_module(1);
    engine->on(engine);
    engine->check(engine);

    engine->fault(engine);
    engine->check(engine);

    engine->off(engine);
    engine->check(engine);

    
}