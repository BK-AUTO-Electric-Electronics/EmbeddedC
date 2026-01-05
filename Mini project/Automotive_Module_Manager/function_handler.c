#include "function_handler.h"
#include "module_manager.h"
#include "bitmask_utils.h"


void module_on(struct Module *m) {
    status_set(&m->status, STATUS_ON);
}


void module_off(struct Module *m) {
    status_clear(&m->status, STATUS_ON);
}


void module_check(struct Module *m) {
    if (!status_check(m->status, STATUS_ON)) {
        status_set(&m->status, STATUS_CANHBAO);
    }
}
