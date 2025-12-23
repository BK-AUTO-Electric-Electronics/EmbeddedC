#include <stdio.h>
#include <assert.h>
#include "error_handler.h"


void check (float y){
    assert (y !=0 && "Lỗi mẫu số bằng 0");
}
