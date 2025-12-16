#include <stdarg.h>
#include "../inc/math_utils.h"
#include "../inc/error_handler.h"



int sum(int count, ...)
{
    int tong = 0;
    va_list args;

    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        tong += va_arg(args, int);
    }

    va_end(args);

    return tong;
}

double divide(void)
{
    int tu, mau;

    tu  = sum(5, 1, 6, 3, 4, 8);
    mau = sum(5, 3, -2, 0, 6, 2);

    check(mau);

    return (double)tu / mau;
}

