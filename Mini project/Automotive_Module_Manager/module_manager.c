#include "module_manager.h"
#include <stdlib.h>
#include <stdio.h>

Module *module_list = NULL;
int module_count = 0;
int module_size = 0;


static int ensure_size(int need) {
    if (need <= module_size) return 1;

    int new_cap = (module_size == 0) ? 4 : (module_size * 2);
    while (new_cap < need) new_cap *= 2;

    Module *tmp = (Module*)realloc(module_list, new_cap * sizeof(Module));
    if (tmp == NULL) {
        printf("!! realloc fail (out of memory)\n");
        return 0;
    }

    module_list = tmp;
    module_size = new_cap;
    return 1;
}

void add_module(int id) {
    if (!ensure_size(module_count + 1)) return;

    module_list[module_count].id = id;
    module_list[module_count].status.raw = 0;

    
    module_list[module_count].ops.on = module_on;
    module_list[module_count].ops.off = module_off;
    module_list[module_count].ops.check = module_check;

    module_count++;
}


int remove_module(int id) {
    for (int i = 0; i < module_count; i++) {
        if (module_list[i].id == id) {
            module_list[i] = module_list[module_count - 1];
            module_count--;
            return 1;
        }
    }
    return 0;
}

Module* find_module(int id) {
    for (int i = 0; i < module_count; i++) {
        if (module_list[i].id == id) return &module_list[i];
    }
    return NULL;
}

void print_modules(const char *title) {
    int i;

    if (title) {
        printf("\n%s\n", title);
    }

    printf("So module: %d\n", module_count);

    for (i = 0; i < module_count; i++) {
        printf("Module %d | BAT=%d LOI=%d CANHBAO=%d\n",
               module_list[i].id,
               module_list[i].status.bit.on,
               module_list[i].status.bit.loi,
               module_list[i].status.bit.canhbao);
    }
}

