#ifndef KID_USER_H
#define KID_USER_H

#include "LibraryUser.h"

typedef struct {
    LibraryUser base;
    int age;
    char bookType[50];
} KidUser;

KidUser* createKidUser();

#endif
