#include <stdlib.h>
#include "arithmetic.h"

static int arithmetic_square(int n) {
    return n * n;
}

Arithmetic* create_arithmetic(void) {
    Arithmetic* a = (Arithmetic*)malloc(sizeof(Arithmetic));
    if (a) {
        a->test_interface.square = arithmetic_square;
    }
    return a;
}

void destroy_arithmetic(Arithmetic* a) {
    free(a);
}
