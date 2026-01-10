#include "bitmask_utils.h"
#include "module_manager.h"
#include "function_handler.h"
#include "error_handler.h"
#include <stdio.h>

  typedef enum 
  {
      them_module = 0,
      xoa_moudule ,
      hien_thi_danh_sach,
      bat_module,
      tat_module,
     tat_chuong_trinh,
     index_max
  }yeu_cau;

  void (*lua_chon[index_max])(void) = {
    [them_module]           = add_module, // tương đương lua_chon[them_module] = add_module;
    [xoa_moudule]           = clear_module,
    [hien_thi_danh_sach]    = display_module,
    [bat_module]            = turn_on_module,
    [tat_module]            = turn_off_module,
    [tat_chuong_trinh]      = exit_program
    };

int main(void) {
    int i;
    yeu_cau yc;

    while (1) {
        printf(
            "\nChon yeu cau:\n"
            "0. Them module\n"
            "1. Xoa module\n"
            "2. Hien thi danh sach\n"
            "3. Bat module\n"
            "4. Tat module\n"
            "5. Tat chuong trinh\n"
            "Lua chon: "
        );

        scanf("%d", &i);

        if (i < 0 || i > index_max) {
            printf("Lua chon khong hop le!\n");
            continue;
        }

        yc = (yeu_cau)(i);
        lua_chon[yc]();
    }
    if(i == 6 ){
    return 0;
    }
}


