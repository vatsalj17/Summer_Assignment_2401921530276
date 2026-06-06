#include <stdlib.h>
#include "KidUser.h"
#include "AdultUser.h"

int main() {
    // Test case #1:
    KidUser *kid = createKidUser();
    LibraryUser *kidUser = (LibraryUser *)kid;
    kidUser->registerAccount(kidUser, 10);
    kidUser->registerAccount(kidUser, 18);
    kidUser->requestBook(kidUser, "Kids");
    kidUser->requestBook(kidUser, "Fiction");

    // Test case #2:
    AdultUser *adult = createAdultUser();
    LibraryUser *adultUser = (LibraryUser *)adult;
    adultUser->registerAccount(adultUser, 5);
    adultUser->registerAccount(adultUser, 23);
    adultUser->requestBook(adultUser, "Kids");
    adultUser->requestBook(adultUser, "Fiction");

    free(kid);
    free(adult);
    return 0;
}
