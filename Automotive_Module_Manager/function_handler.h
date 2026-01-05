#ifndef FUNCTION_HANDLER_H
#define FUNCTION_HANDLER_H
typedef struct Module_manager Module;
void module_on( Module *);
void module_off( Module *);
void module_fault( Module *);
void module_check( Module *);
#endif