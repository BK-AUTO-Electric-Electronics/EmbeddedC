#include <stdio.h>
#include "math_utils.h"
#include "error_handler.h"

int main() {
    double result = divide(4, 1, 1, 2, 3, 4, 1);
    printf ("Result = %f\n", result);
    return 0;
}