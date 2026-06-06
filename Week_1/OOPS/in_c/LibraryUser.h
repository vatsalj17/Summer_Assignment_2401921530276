#ifndef LIBRARY_USER_H
#define LIBRARY_USER_H

// Interface
typedef struct LibraryUser {
    void (*registerAccount)(struct LibraryUser *self, int age);
    void (*requestBook)(struct LibraryUser *self, char *bookType);
} LibraryUser;

#endif
