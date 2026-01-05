#include <stdio.h>
#include "function_handler.h"
#include "module_manager.h"
#include "bitmask_utils.h"
#include "error_handler.h"

static Module* find_by_id(uint8_t id) {
    for (int i = 0; i < module_count; i++) {
        if (list_modules[i].id == id) return &list_modules[i];
    }
    return NULL;
}


void turn_on_module(uint8_t id) {
    Module* m = find_by_id(id);
    if (m) {
        set_status(&m->status, STATUS_ON);
        // Reset lỗi và cảnh báo khi bắt đầu bật
        clear_status(&m->status, STATUS_ERROR | STATUS_WARNING);
        printf("[SYSTEM] %s: ON\n", m->name);
    }
}


void turn_off_module(uint8_t id) {
    Module* m = find_by_id(id);
    if (m) {
        clear_status(&m->status, STATUS_ON);
        printf("[SYSTEM] %s: OFF\n", m->name);
    }
}


void check_module_status(uint8_t id) {
    Module* m = find_by_id(id);
    if (!m) return;

    printf("[CHECK] %s: ", m->name);
    
    if (check_status(m->status, STATUS_ERROR)) {
        printf("STATUS ERROR! ");
        // Gọi hàm chứa longjmp để thoát về vùng an toàn
        handle_critical_error(m->name); 
    } 
    else if (check_status(m->status, STATUS_WARNING)) {
        printf("STATUS WARNING\n");
    } 
    else {
        printf("STATUS OK\n");
    }
}



