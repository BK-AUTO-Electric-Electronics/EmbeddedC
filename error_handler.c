#include <stdio.h>
#include "error_handler.h"
#include "bitmask_utils.h"

jmp_buf buf;

void fake_error(Module *m) {
    m->status.bits.error = 1;
}

void check_error(Module *m) {
    if(m->status.bits.error != 0) {
        longjmp(buf, 1);
    }
}

void warning(Module *m) {
    check_error(m);
    TRY{
        printf("OPERATING NORMALLY\n");
    };

    CATCH{
        printf("ERROR DETECTED\n");
    };
}