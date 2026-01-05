#include <stdio.h>
#include <stdlib.h>

#include "module_manager.h"
#include "error_handler.h"
#include "bitmask_utils.h"

int main(void) {
    Module *m;

  
    add_module(1); 
    add_module(2); 
    add_module(3); 
    add_module(4); 
    add_module(5); 
    print_modules(" Khoi tao 5 module");

    
    if (setjmp(safe_point) != 0) {
        printf(" he thong bi loi quay ve safe point\n");
        safe_reset();
        print_modules("SAU SAFE RESET");

        free(module_list);
        module_list = NULL;
        module_count = 0;
        module_size = 0;
        return 0;
    }

    
    m = find_module(1);
    if (m) m->ops.on(m);
    m = find_module(2);
    if (m) m->ops.on(m);
    print_modules(" Bat module 1 va 2");

    
    m = find_module(3);
    if (m) m->ops.check(m);
    print_modules(" Check module 3 (OFF -> CANHBAO)");

    
    add_module(6);
    print_modules(" Them module 6");

    
    remove_module(4);
    print_modules(" Xoa module 4 ");

    
    m = find_module(2);
    if (m) {
        status_set(&m->status, STATUS_LOI);
        print_modules(" Module 2 BI LOI ");
        longjmp(safe_point, 1);
    }

    free(module_list);
    return 0;
}
