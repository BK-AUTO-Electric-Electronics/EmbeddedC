#include<stdio.h>
#include<stdarg.h>
#include"math_utils.h"
#include"error_handler.h"
float divide(int x_count, int y_count, ...){
    float x =0;
    float y = 0;
    va_list args;
    va_start(args, y_count);
    for (int i=0; i<x_count; i++){
        x += va_arg(args, int);
    }
    for (int i=0; i<y_count; i++){
        y += va_arg(args, int);
    }
    va_end(args);
    check(y);
    return x/y;
}
