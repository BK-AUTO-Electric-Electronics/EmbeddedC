#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H
#include<stdint.h>
typedef struct Module_manager Module;
typedef void (*ModuleAction)(Module *);
 struct Module_manager{
    uint8_t ID;
    char name[12];
    uint8_t status;

    ModuleAction on;
    ModuleAction off;
    ModuleAction fault;
    ModuleAction check;
};


#endif
