#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "KidUser.h"

void kid_registerAccount(LibraryUser *self, int age) {
    KidUser *kid = (KidUser *)self;
    kid->age = age;

    if (age < 12) {
        printf("You have successfully registered under a Kids Account\n");
    } else {
        printf("Sorry, Age must be less than 12 to register as a kid\n");
    }
}

void kid_requestBook(LibraryUser *self, char *bookType) {
    KidUser *kid = (KidUser *)self;
    strcpy(kid->bookType, bookType);

    if (strcmp(bookType, "Kids") == 0) {
        printf("Book Issued successfully, please return the book within 10 days\n");
    } else {
        printf("Oops, you are allowed to take only kids books\n");
    }
}

KidUser* createKidUser() {
    KidUser *kid = (KidUser *)malloc(sizeof(KidUser));
    kid->base.registerAccount = kid_registerAccount;
    kid->base.requestBook = kid_requestBook;
    return kid;
}
