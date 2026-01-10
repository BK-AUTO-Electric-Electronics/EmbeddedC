#include "module_manager.h"
#include <stdio.h>
#include <stdlib.h>

Module *module_list;
int module_qty;
void begin_module(void){
    module_list = NULL;
    module_qty = 0;
}

void add_module(void)
{
    int id;
    char name[40];
    printf("nhap id: ");
    scanf("%d", &id);
    getchar();
    printf("nhap ten module: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    Module *new_list = realloc(module_list,(module_qty + 1) * sizeof(Module));
    if (new_list == NULL) {
    printf("Cap phat bo nho that bai\n");
    return;
    }
    module_list = new_list; // tránh ghi đè trực tiếp, nếu realloc thất bại thì module_list vẫn còn
    module_list[module_qty].id = id;
    strcpy(module_list[module_qty].name, name);;
    module_list[module_qty].status = 0;
    strcpy(module_list[module_qty].state,"NONE");
    module_qty++;
}


void clear_module(void) 
{
    int id;
    printf("nhap id: ");
    scanf("%d", &id);
    int index = -1;
    for (int i = 0; i < module_qty; i++) {
        if (module_list[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
    return;
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

}

void display_module(void){
   printf("ID------Ten------trang thai\n");
   for(int i=0; i <module_qty;i++){
        printf("%d       %s        %s\n", module_list[i].id, module_list[i].name, module_list[i].state);
    }

}

void exit_program(void){
    printf("BYE BYE");
}
