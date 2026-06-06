#ifndef ADULT_USER_H
#define ADULT_USER_H

#include "LibraryUser.h"

typedef struct {
    LibraryUser base;
    int age;
    char bookType[50];
} AdultUser;

AdultUser* createAdultUser();

#endif
