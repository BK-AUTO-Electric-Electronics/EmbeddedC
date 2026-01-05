#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H
#include <setjmp.h>

extern jmp_buf safe_state_buffer;

typedef enum {
    SUCCESS = 0,
    CRITICAL_ERROR = 1
} ErrorCode;

void trigger_emergency_stop(const char* module_name);

#endif