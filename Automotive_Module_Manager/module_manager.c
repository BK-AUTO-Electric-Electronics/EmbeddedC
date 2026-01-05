#include "module_manager.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void init_system(ModuleSystem *sys) {
    sys->modules = NULL;
    sys->size = 0;
}

void add_module(ModuleSystem *sys, int id, const char *name, void (*control_func)(Module*, int)) {
    // Nới rộng vùng nhớ thêm 1 đơn vị Module mỗi khi add
    Module *temp = realloc(sys->modules, (sys->size + 1) * sizeof(Module));
    
    if (temp == NULL) {
        printf("Loi: Khong the cap phat bo nho!\n");
        return;
    }
    
    sys->modules = temp;
    sys->modules[sys->size].id = id;
    strncpy(sys->modules[sys->size].name, name, 29);
    sys->modules[sys->size].status = 0; // Mac dinh ban dau la OFF
    sys->modules[sys->size].control = control_func;
    
    sys->size++;
    printf("[SYSTEM] Da them Module: %s (ID: %d)\n", name, id);
}

void cleanup_system(ModuleSystem *sys) {
    if (sys->modules != NULL) {
        free(sys->modules); // Giai phong vung nho dong
        sys->modules = NULL;
        sys->size = 0;
        printf("[SYSTEM] Da giai phong bo nho he thong.\n");
    }
}