#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "module_manager.h"

Module* list_modules = NULL;
int module_count = 0;

void add_module(uint8_t id, const char* name, void (*handler)(uint8_t)) {
    Module* temp = realloc(list_modules, (module_count + 1) * sizeof(Module));
    if (temp == NULL) {
        printf("Lỗi: Không thể cấp phát bộ nhớ!\n");
        return;
    }
    list_modules = temp;
    list_modules[module_count].id = id;
    strcpy(list_modules[module_count].name, name);
    list_modules[module_count].status = STATUS_OFF;
    list_modules[module_count].on_status_change = handler;
    module_count ++;
    printf("Đã thêm module: %s (ID: %d)\n", name, id);
}

void remove_module(uint8_t id) {
    int index = -1;
    for (int i = 0; i < module_count; i++) {
        if(list_modules[i].id == id) {
            index = i; // Module cần xóa là module thứ i+1 trong list_module
            break;
        }
    }

    if (index != -1) {
        printf("Đang xóa module: %s (ID: %d)...\n", list_modules[index].name, id);
        
        // Dồn các module trong list_module từ vị trí i+1 trở đi lên 1 vị trí để xóa module thứ i
        for (int i = index; i < module_count - 1; i++) {
            list_modules[i] = list_modules[i+1];
        }

        module_count --;
        if (module_count > 0) {
            list_modules = realloc(list_modules, module_count * sizeof(Module));
        }
        else {
            free(list_modules);
            list_modules = NULL;
        }
        printf("Xóa thành công.\n");

    }
    else {
        printf("Lỗi: Không tìm thấy module ID %d để xóa.\n", id);
    }
}

void cleanup_modules() {
    if (list_modules != NULL) {
        free(list_modules);
        list_modules = NULL;
    }
    module_count = 0;
}