#ifndef MODUL_MANAGER_H
#define MODUL_MANAGER_H

typedef union {
    unsigned char status;
    struct {
        unsigned char on      : 1;
        unsigned char error   : 1;
        unsigned char warning : 1;
    } bits;
} ModuleStatus;

typedef struct Module {
    int id;
    char name[32];
    ModuleStatus status;

    void (*turn_on)(struct Module*);
    void (*turn_off)(struct Module*);
    void (*check)(struct Module*);
} Module;

void add_module(const char *name, void (*on)(Module*), void (*off)(Module*), void (*check)(Module*));

void remove_module(int id);
void list_modules(void);
Module* get_module(int id);
void free_modules(void);

#endif