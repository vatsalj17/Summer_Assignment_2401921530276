#ifndef BOX_H
#define BOX_H

typedef struct Box {
    double length;
    double breadth;
    void (*set_length)(struct Box*, double);
    void (*set_breadth)(struct Box*, double);
    double (*get_area)(struct Box*);
} Box;

void init_box(Box* b, double length, double breadth);

#endif
