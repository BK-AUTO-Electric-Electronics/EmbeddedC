#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "module_manager.h"
#include "function_handler.h"


Module *modules=NULL;
uint8_t module_count=0;
void add_module(uint8_t ID, const char *name) {
    Module *m = &modules[module_count];
    modules=realloc(modules, (module_count + 1) * sizeof(Module));
    m->ID =ID;
    strcpy(m->name, name);
    m->on    = module_on;
    m->off   = module_off;
    m->fault = module_fault;
    m->check = module_check;
    m->status =0;
    module_count++;
}
void remove_module(uint8_t ID) {
    for(uint8_t i, i < module_count, i++) { 
        if(modules[i].ID==ID) {
            modules[i]= modules[module_count-1];
            module_count--;
            modules=realloc(modules, (module_count)* sizeof(Module));
        }
    }
    
}
Module *get_module(uint8_t ID) {
    for(uint8_t i, i<=module_count, i++) {
        if(modules[i].ID==ID) {
            return &modules[i];
        }
        return 0;
    }

}