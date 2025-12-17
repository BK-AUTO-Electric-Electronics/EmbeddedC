#include "error_handler.h"
#include <stdarg.h>
#include "math_utils.h"

float devide(int count_1,int count_2,...){
    va_list args;
    va_start(args,count_2 );

    int sum_numerator=0;
    int sum_denominator=0;

    for(int i=0; i<count_1;i++){
        sum_numerator += va_arg(args,int);
    }
    for(int i=0; i<count_2;i++){
        sum_denominator += va_arg(args,int);
    }

    va_end(args);

    check_division(sum_denominator);

    return (float)sum_numerator/sum_denominator;
}