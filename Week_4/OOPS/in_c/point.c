#include <stdlib.h>
#include "point.h"

static void point_set_x(Point* self, int x) {
    self->x = x;
}

static void point_set_y(Point* self, int y) {
    self->y = y;
}

static void point_set_xy(Point* self, int x, int y) {
    self->x = x;
    self->y = y;
}

static void init_point_methods(Point* p) {
    p->set_x = point_set_x;
    p->set_y = point_set_y;
    p->set_xy = point_set_xy;
}

Point* create_point_default(void) {
    Point* p = (Point*)malloc(sizeof(Point));
    if (p) {
        p->x = 0;
        p->y = 0;
        init_point_methods(p);
    }
    return p;
}

Point* create_point(int x, int y) {
    Point* p = (Point*)malloc(sizeof(Point));
    if (p) {
        p->x = x;
        p->y = y;
        init_point_methods(p);
    }
    return p;
}

void destroy_point(Point* p) {
    free(p);
}
