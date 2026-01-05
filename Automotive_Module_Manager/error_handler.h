#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <setjmp.h>

jmp_buf error_jump;

void throw_error(void);

#endif