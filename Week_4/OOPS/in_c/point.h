#ifndef POINT_H
#define POINT_H

typedef struct Point {
    int x;
    int y;
    void (*set_x)(struct Point*, int);
    void (*set_y)(struct Point*, int);
    void (*set_xy)(struct Point*, int, int);
} Point;

Point* create_point_default(void);
Point* create_point(int x, int y);
void destroy_point(Point* p);

#endif
