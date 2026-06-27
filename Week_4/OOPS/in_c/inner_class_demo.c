#include <stdio.h>
#include <stdlib.h>

typedef struct InnerClassDemo InnerClassDemo;
typedef struct InnerClass InnerClass;

struct InnerClassDemo {
    void (*display)(InnerClassDemo*);
};

struct InnerClass {
    InnerClassDemo* outer;
    void (*display)(InnerClass*);
};

static void outer_display(InnerClassDemo* self) {
    (void)self;
    printf("Outer class display\n");
}

static void inner_display(InnerClass* self) {
    (void)self;
    printf("Inner class display\n");
}

InnerClassDemo* create_outer(void) {
    InnerClassDemo* outer = (InnerClassDemo*)malloc(sizeof(InnerClassDemo));
    if (outer) outer->display = outer_display;
    return outer;
}

InnerClass* create_inner(InnerClassDemo* outer) {
    InnerClass* inner = (InnerClass*)malloc(sizeof(InnerClass));
    if (inner) {
        inner->outer = outer;
        inner->display = inner_display;
    }
    return inner;
}

int main(void) {
    InnerClassDemo* outer = create_outer();
    if (outer) {
        outer->display(outer);

        InnerClass* inner = create_inner(outer);
        if (inner) {
            inner->display(inner);
            free(inner);
        }
        free(outer);
    }
    return 0;
}
