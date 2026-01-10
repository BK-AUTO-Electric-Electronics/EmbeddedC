#include "module_manager.h"
#include "function_handler.h"
#include "bitmask_utils.h"
#include "error_handler.h"
#include <stdio.h>


void turn_on_module(void) {
    int id;
    printf("Nhap id module can bat: ");
    scanf("%d", &id);

    for (int i = 0; i < module_qty; i++) {
        if (module_list[i].id == id) {

            set_status(&module_list[i].status, STATUS_ON);
            clear_status(&module_list[i].status,STATUS_ERROR | STATUS_WARNING);

            strcpy(module_list[i].state, "ON");

            printf("TURN ON MODULE %d\n", id);
            return;
        }
    }

    printf("Khong tim thay module co id %d\n", id);
}

void turn_off_module(void) {
    int id;
    printf("Nhap id module can tat: ");
    scanf("%d", &id);

    for (int i = 0; i < module_qty; i++) {
        if (module_list[i].id == id) {
            clear_status(&module_list[i].status,STATUS_ON);
            
            strcpy(module_list[i].state, "OFF");

            printf("TURN OFF MODULE %d\n", id);
            return;
        }
    }

    printf("Khong tim thay module co id %d\n", id);
}

void check_module(void) {
    int id;
    printf("Nhap id module can check: ");
    scanf("%d", &id);
    for (int i=0; i < module_qty; i++){
        if(module_list[i].id == id) {

        if (check_status(module_list[i].status, STATUS_ERROR)) {
        printf("ERROR\n");
        throw_error();
    }
        else if (check_status(module_list[i].status, STATUS_WARNING)) {
        printf("WARNING\n");
        strcpy(module_list[i].state, "WARNING");
    }
        else {
        printf("OK\n");
    }
    
    }
    return;
 }
 printf("Khong tim thay module co id %d\n", id);
}

