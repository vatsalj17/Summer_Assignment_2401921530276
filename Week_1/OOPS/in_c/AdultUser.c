#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AdultUser.h"

void adult_registerAccount(LibraryUser *self, int age) {
    AdultUser *adult = (AdultUser *)self;
    adult->age = age;

    if (age > 12) {
        printf("You have successfully registered under an Adult Account\n");
    } else {
        printf("Sorry, Age must be greater than 12 to register as an adult\n");
    }
}

void adult_requestBook(LibraryUser *self, char *bookType) {
    AdultUser *adult = (AdultUser *)self;
    strcpy(adult->bookType, bookType);

    if (strcmp(bookType, "Fiction") == 0) {
        printf("Book Issued successfully, please return the book within 7 days\n");
    } else {
        printf("Oops, you are allowed to take only adult Fiction books\n");
    }
}

AdultUser* createAdultUser() {
    AdultUser *adult = (AdultUser *)malloc(sizeof(AdultUser));
    adult->base.registerAccount = adult_registerAccount;
    adult->base.requestBook = adult_requestBook;
    return adult;
}
