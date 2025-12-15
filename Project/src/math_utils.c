#include<stdio.h>
#include<stdarg.h>
#include"math_utils.h"
#include"error_handler.h"
float divide(int a_count, int b_count, ...){
    float a =0;
    float b = 0;
    va_list args;
    va_start(args, b_count);
    for (int i=0; i<a_count; i++){
        a += va_arg(args, int);
    }
    for (int i=0; i<b_count; i++){
        b += va_arg(args, int);
    }
    va_end(args);
    test1(b);
    return a/b;
}

