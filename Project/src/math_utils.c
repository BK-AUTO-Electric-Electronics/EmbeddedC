#include <stdio.h>
#include <stdarg.h>
#include "math_utils.h"
#include "error_handler.h"

double divide(int tong_tu, int tong_mau, ...) {
    int mau = 0;
    int tu = 0;
    va_list args;
    va_start(args, tong_mau);

    //Tính tử
    for (int i = 0;i < tong_tu;i++) {
        tu += va_arg(args, int);
    }

    //Tính mẫu
    for (int i = 0;i < tong_mau;i++) {
        mau += va_arg(args, int);
    }
    
    va_end(args);
    
    //Kiểm tra lỗi
    handle_divide_error(mau);

    return (double) tu/mau;
}