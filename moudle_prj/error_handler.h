#ifndef ERROR_MANAGER_H
#define ERROR_MANAGER_H

#include <setjmp.h>

extern jmp_buf error;

void throw_error(void);

#endif
