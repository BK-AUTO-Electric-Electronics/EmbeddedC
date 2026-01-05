#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <setjmp.h>

extern jmp_buf save_state;
void handle_critical_error(const char* module_name);

#endif