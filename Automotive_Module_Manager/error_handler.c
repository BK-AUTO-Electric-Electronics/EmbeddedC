#include "error_handler.h"

jmp_buf error_jump;

void throw_error(void) {
    longjmp(error_jump, 1);
}