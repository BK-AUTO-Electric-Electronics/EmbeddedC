#include <stdio.h>
#include "error_handler.h"
#include "math_utils.h"
int main() {
    double thuong = divide(4,3,1,2,3,4,1,2,3);
    printf("thuong= %.2f", thuong);
    return 0;
}