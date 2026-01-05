#include <stdio.h>
#include <setjmp.h>
#include "module_manager.h"
#include "function_handler.h"
#include "error_handler.h"

int main() {



    add_module("Engine ECU", engine_on, engine_off, engine_check);
    add_module("ABS ECU", abs_on, abs_off, abs_check);

    list_modules();

    Module *engine = get_module(0);
    //fake_error(engine);
    engine->turn_on(engine);
    engine->check(engine);

    Module *abs = get_module(1);
    fake_error(abs);
    //abs->turn_on(abs);
    abs->check(abs);

    remove_module(0);
    
    list_modules();
    free_modules();
    return 0;
}
