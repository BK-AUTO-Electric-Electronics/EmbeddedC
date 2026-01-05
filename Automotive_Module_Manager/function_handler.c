#include "function_handler.h"
#include "bitmask_utils.h"
#include <stdio.h>

void engine_control_logic(Module *m, int cmd) {
    if (cmd == 1) {
        set_status(&(m->status), STATUS_ON);
        printf("   Action: Engine Powered ON.\n");
    }
}

void abs_control_logic(Module *m, int cmd) {
    if (cmd == 1) {
        set_status(&(m->status), STATUS_ON);
        printf("   Action: ABS Activating...\n");
        // Giả lập lỗi cho ID 2
        if (m->id == 2) {
            set_status(&(m->status), STATUS_ERROR);
        }
    }
}