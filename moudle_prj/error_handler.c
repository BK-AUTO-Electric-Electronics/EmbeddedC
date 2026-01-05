#include "error_handler.h"
#include <stdio.h>

jmp_buf error;

void throw_error(void) {
    printf("Module error\n");
    longjmp(error, 1);
}
