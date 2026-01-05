#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "module_manager.h"

static Module *modules = NULL;
static int module_count = 0;

void add_module(const char *name, void (*on)(Module*), void (*off)(Module*), void (*check)(Module*)) {

    // Them bo nho cap phat
    modules = realloc(modules, (module_count + 1) * sizeof(Module));

    Module *m = &modules[module_count];
    m->id = module_count;
    strncpy(m->name, name, sizeof(m->name));
    m->status.status = 0;

    m->turn_on = on;
    m->turn_off = off;
    m->check = check;

    module_count++;
}

void remove_module(int id) {
    if (id < 0 || id >= module_count) return;
    printf("\n=== REMOVED ===\nID: %d | Name: %s \n", id, modules[id].name);
    for (int i = id; i < module_count - 1; i++) {
        modules[i] = modules[i + 1];
        modules[i].id = i;
    }

    module_count--;
    modules = realloc(modules, module_count * sizeof(Module));
}



void list_modules(void) {
    printf("\n=== MODULE LIST ===\n");
    for (int i = 0; i < module_count; i++) {
        printf("ID: %d | Name: %s \n",
               modules[i].id,
               modules[i].name);
    }
}

Module* get_module(int id) {
    if (id < 0 || id >= module_count) return NULL;
    return &modules[id];
}

void free_modules(void) {
    free(modules);
}