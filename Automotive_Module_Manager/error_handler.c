#include "error_handler.h"
#include <stdio.h>

// Khai báo bộ nhớ đệm để lưu trạng thái ngăn xếp cho setjmp/longjmp
jmp_buf safe_state_buffer;

void trigger_emergency_stop(const char* module_name) {
    printf("\n[ERROR HANDLER] Dang xu ly su co tai: %s\n", module_name);
    printf("[ERROR HANDLER] Lenh: Nhay ve trang thai an toan (Longjmp)...\n");
    
    // Thực hiện cú nhảy về điểm setjmp trong main
    // Giá trị 1 sẽ được trả về cho setjmp
    longjmp(safe_state_buffer, 1);
}