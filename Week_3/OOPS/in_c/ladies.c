#include <stdlib.h>
#include "compartment.h"

static const char *ladies_notice(void) {
	return "Notice: Ladies Compartment";
}

Compartment *create_ladies(void) {
	Compartment *c = malloc(sizeof(Compartment));
	c->notice = ladies_notice;
	return c;
}
