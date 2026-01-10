#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H
#include <stdint.h>
#include <string.h>

typedef struct Module {
    int id;
    char name[32];  
    uint8_t status;
    char state [10];
    void (*on)(void);
    void (*off)(void);
    void (*check)(void);
} Module;

extern Module *module_list;
extern int module_qty;

void begin_module(void);

void add_module( void);
void clear_module(void);
void display_module(void);
void exit_program(void);
#endif