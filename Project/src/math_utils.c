#include<stdio.h>
#include<stdarg.h>
#include "error_handler.h"
#include "math_utils.h"
double divide(int count_x, int count_y,...){
    va_list args;
    int tu=0;
    int mau=0;
    va_start(args, count_y);
    for(int i=0; i< count_x;i++) {
    tu+= va_arg(args, int);         
    }
    for(int j=0;j<count_y;j++) {
        mau+= va_arg(args, int);
    }
    va_end(args);
    check (mau);
    return (double) tu/mau;
}