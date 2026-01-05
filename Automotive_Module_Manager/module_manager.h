#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H

typedef struct Module {
    int id;
    char name[30];
    unsigned char status; 
    void (*control)(struct Module*, int); // Function pointer: (module, command 1:ON / 0:OFF)
} Module;

typedef struct {
    Module *modules;
    int size;
} ModuleSystem;

void init_system(ModuleSystem *sys);
void add_module(ModuleSystem *sys, int id, const char *name, void (*control_func)(Module*, int));
void cleanup_system(ModuleSystem *sys);

#endif