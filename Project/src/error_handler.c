#include<stdio.h>
#include<assert.h>
#include"error_handler.h"

void test1( float b) {
    assert("Loi mau bang 0" && (b !=0));
}