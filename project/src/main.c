#include <stdio.h>
#include <assert.h>

#include "math_utils.h"
#include "error_handler.h"
   

int main(){
    int tu = sum(3,1,2,3);
    int mau = sum(2,1,6);
    error_check(mau);
    printf("%.2f", (float)tu/mau);
    return 0;

}