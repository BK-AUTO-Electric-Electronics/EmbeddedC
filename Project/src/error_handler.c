#include <assert.h>
#include "error_handler.h"

void handle_divide_error(float mau) {
    assert(mau != 0 && "Error: Mau bang = 0");
}