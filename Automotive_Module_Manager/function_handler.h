#ifndef FUNCTION_HANDLER_H
#define FUNCTION_HANDLER_H

#include "module_manager.h"


void engine_on(Module *m);
void engine_off(Module *m);
void engine_check(Module *m);

void abs_on(Module *m);
void abs_off(Module *m);
void abs_check(Module *m);

#endif
