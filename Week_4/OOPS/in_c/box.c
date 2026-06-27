#include "box.h"

static void box_set_length(Box* self, double length) {
    self->length = length;
}

static void box_set_breadth(Box* self, double breadth) {
    self->breadth = breadth;
}

static double box_get_area(Box* self) {
    return self->length * self->breadth;
}

void init_box(Box* b, double length, double breadth) {
    b->length = length;
    b->breadth = breadth;
    b->set_length = box_set_length;
    b->set_breadth = box_set_breadth;
    b->get_area = box_get_area;
}
