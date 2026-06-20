#include <stdlib.h>
#include "compartment.h"

static const char *first_class_notice(void) {
	return "Notice: First Class Compartment";
}

Compartment *create_first_class(void) {
	Compartment *c = malloc(sizeof(Compartment));
	c->notice = first_class_notice;
	return c;
}
