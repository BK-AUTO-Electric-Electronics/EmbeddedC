#ifndef FUNCTION_HANDLER_H
#define FUNCTION_HANDLER_H

struct Module;

typedef void (*ModuleFunc)(struct Module*);

typedef struct {
    ModuleFunc on;
    ModuleFunc off;
    ModuleFunc check;
} ModuleOps;


void module_on(struct Module *m);
void module_off(struct Module *m);
void module_check(struct Module *m);

#endif
