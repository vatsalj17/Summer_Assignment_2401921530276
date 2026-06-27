#ifndef ARITHMETIC_H
#define ARITHMETIC_H
#include "test.h"

typedef struct Arithmetic {
    Test test_interface;
} Arithmetic;

Arithmetic* create_arithmetic(void);
void destroy_arithmetic(Arithmetic* a);

#endif
