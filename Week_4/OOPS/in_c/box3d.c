#include <stdio.h>
#include <stdlib.h>
#include "box.h"

typedef struct Box3d {
    Box base;
    double height;
    void (*set_height)(struct Box3d*, double);
    double (*get_volume)(struct Box3d*);
} Box3d;

static void box3d_set_height(Box3d* self, double height) {
    self->height = height;
}

static double box3d_get_volume(Box3d* self) {
    return self->base.length * self->base.breadth * self->height;
}

Box3d* create_box3d(double length, double breadth, double height) {
    Box3d* b3d = (Box3d*)malloc(sizeof(Box3d));
    if (b3d) {
        init_box(&b3d->base, length, breadth);
        b3d->height = height;
        b3d->set_height = box3d_set_height;
        b3d->get_volume = box3d_get_volume;
    }
    return b3d;
}

void destroy_box3d(Box3d* b3d) {
    free(b3d);
}

int main(void) {
    Box3d* myBox = create_box3d(2.0, 3.0, 4.0);
    if (myBox) {
        printf("Area: %f\n", myBox->base.get_area(&myBox->base));
        printf("Volume: %f\n", myBox->get_volume(myBox));

        myBox->base.set_length(&myBox->base, 5.0);
        myBox->base.set_breadth(&myBox->base, 6.0);
        myBox->set_height(myBox, 7.0);

        printf("New Area: %f\n", myBox->base.get_area(&myBox->base));
        printf("New Volume: %f\n", myBox->get_volume(myBox));

        destroy_box3d(myBox);
    }
    return 0;
}
