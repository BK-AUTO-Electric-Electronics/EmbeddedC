#include <stdio.h>
#include <stdlib.h>
#include "module_manager.h"
#include "bitmask_utils.h"
#include "function_handler.h"
#include "error_handler.h"

int main() {
    // --- BƯỚC 1 & 3: PHÂN TÍCH & TRIỂN KHAI QUẢN LÝ MODULE ---
    printf("========== HE THONG QUAN LY MODULE O TO ==========\n");
    
    // Thêm các module vào danh sách (Sử dụng cấp phát động realloc bên trong)
    add_module(1, "Dong co (ECU)", NULL);
    add_module(2, "He thong phanh (ABS)", NULL);
    add_module(3, "He thong Den", NULL);
    add_module(4, "Dieu hoa (AC)", NULL);
    add_module(5, "Cam bien nhiet do", NULL);

    // --- BƯỚC 4: XỬ LÝ LỖI VỚI SETJMP/LONGJMP ---
    // Thiết lập điểm phục hồi an toàn
    if (setjmp(save_state) == 0) {
        printf("\n[LOG] He thong khoi dong thanh cong.\n");

        // --- BƯỚC 3: KIỂM TRA & THAY ĐỔI TRẠNG THÁI ---
        
        // 1. Van hanh binh thuong
        turn_on_module(1); // Bat Dong co
        turn_on_module(2); // Bat ABS
        check_module_status(1);
        check_module_status(2);

        // 2. Gia lap canh bao (Warning)
        printf("\n[CANH BAO]: Kiem tra cam bien nhiet do...\n");
        set_module_warning(5);
        check_module_status(5);

        // 3. Gia lap tinh huong xoa module (Gia su module AC bi thao go)
        printf("\n[BAO TRI]: Thao go he thong Dieu hoa...\n");
        remove_module(4);

        // 4. Gia lap LOI NGHIEM TRONG (Error)
        printf("\n[NGUY HIEM]: He thong phanh ABS gap su co!\n");
        set_module_error(2); 

        // Ham nay se kiem tra bitmask va goi longjmp vi co STATUS_ERROR
        check_module_status(2); 

        // Doan code phia duoi se bi bo qua khi longjmp duoc kich hoat
        printf("Dong nay se khong bao gio duoc in ra.\n");

    } else {
        // --- TRẠNG THÁI AN TOÀN (SAFE MODE) ---
        printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("!!! PHAT HIEN LOI NGUY HIEM - JUMP TO SAFE MODE !!!\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");

        // Xu ly dua cac module ve trang thai an toan
        for (int i = 0; i < module_count; i++) {
            turn_off_module(list_modules[i].id);
            clear_module_error(list_modules[i].id);
            printf("[SAFE] Da ngat nguon module: %s\n", list_modules[i].name);
        }
        printf("\n[HT]: He thong da duoc cach ly an toan.\n");
    }

    // --- KẾT THÚC & GIẢI PHÓNG ---
    printf("\n[HT]: Tien hanh giai phong bo nho va tat he thong.\n");
    cleanup_modules(); 
    
    return 0;
}