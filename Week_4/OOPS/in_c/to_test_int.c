#include <stdio.h>
#include "arithmetic.h"

int main(void) {
    Arithmetic* obj = create_arithmetic();
    if (obj) {
        printf("%d\n", obj->test_interface.square(5));
        destroy_arithmetic(obj);
    }
    return 0;
}
