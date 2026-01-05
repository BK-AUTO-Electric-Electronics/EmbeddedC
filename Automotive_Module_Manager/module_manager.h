#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H

#include <stdint.h>
#include "bitmask_utils.h"

typedef struct 
{
    uint8_t id;
    char name[30];
    uint8_t status;
    void (*on_status_change) (uint8_t new_status);
} Module;

extern Module* list_modules;
extern int module_count;

void add_module(uint8_t id, const char* name, void (*handler)(uint8_t));
void remove_module(uint8_t id);
void cleanup_modules();

#endif 