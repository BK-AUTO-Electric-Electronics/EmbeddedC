#include "bitmask_utils.h"
#include "module_manager.h"
#include "function_handler.h"
#include "error_handler.h"
#include <stdio.h>

int main() {
    Module m1_obj = {0};
    Module *m1 = &m1_obj;

    printf("nhap id module: ");
    scanf("%d", &m1->id);
    getchar();

    printf("nhap ten module: ");
    fgets(m1->name, sizeof(m1->name), stdin);

    m1->on    = turn_on_module;
    m1->off   = turn_off_module;
    m1->check = check_module;

    add_module(m1);

    if (setjmp(error) == 0) {
        m1->on(m1);
        m1->check(m1);
        printf("Module OK\n");
    } else {
        printf("ERROR detected!\n");
    }

    return 0;
}


