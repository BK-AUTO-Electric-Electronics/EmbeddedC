#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H
#include <stdint.h>
#include <string.h>

typedef struct Module {
    int id;
    char name[32];  
    uint8_t status;
    void (*on)(struct Module *);
    void (*off)(struct Module *);
    void (*check)(struct Module *);
} Module;


void begin_module(void);
int add_module( Module *m);
int clear_module(int id);

#endif