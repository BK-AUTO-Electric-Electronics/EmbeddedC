#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <setjmp.h>
#include "module_manager.h"
#include "bitmask_utils.h"

#define TRY if(setjmp(buf) == 0)
#define CATCH if(setjmp(buf) == 1)
void check_error(Module *m);
void warning(Module *m);
void fake_error(Module *m);

#endif

