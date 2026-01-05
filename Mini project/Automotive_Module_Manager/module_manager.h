#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H

#include "bitmask_utils.h"
#include "function_handler.h"


typedef struct Module {
    int id;
    ModuleStatus status;
    ModuleOps ops;
} Module;


extern Module *module_list;
extern int module_count;
extern int module_size;  


void add_module(int id);
int  remove_module(int id);        
Module* find_module(int id);
void print_modules(const char *title);

#endif
