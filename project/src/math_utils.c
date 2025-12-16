#include"math_utils.h"
#include <stdarg.h>

int sum(int count,...){
    va_list ap;
    int tong = 0;
    va_start(ap,count);
    for(int i=0; i< count; i++){
        tong+=va_arg(ap, int);

    }
    va_end(ap);
return tong;
}
