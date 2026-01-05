#include "module_manager.h"
#include <stdio.h>
#include <stdlib.h>

static Module *module_list;
static int module_qty;

void begin_module(void){
    module_list = NULL;
    module_qty = 0;
}

int add_module(Module *m) {
    Module *new_list = realloc(module_list,(module_qty + 1) * sizeof(Module));
    if (new_list == NULL) {
        return 0;
    }

    module_list = new_list; // tránh ghi đè trực tiếp, nếu realloc thất bại thì module_list vẫn còn
    module_list[module_qty] = *m;
    module_qty++;
    return 1;
}


int clear_module(int id) {
    int index = -1;
    for (int i = 0; i < module_qty; i++) {
        if (module_list[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        return 0; 
    }

    for (int i = index; i < module_qty - 1; i++) {
        module_list[i] = module_list[i + 1];
    }

    module_qty--;

    if (module_qty == 0) {
        free(module_list);
        module_list = NULL;
    } else {
        Module *new_list = realloc(module_list,module_qty * sizeof(Module));                                  
        if (new_list != NULL) {
            module_list = new_list;
        }
    }

    return 1;
}
