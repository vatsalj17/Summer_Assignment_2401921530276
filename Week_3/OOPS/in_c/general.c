#include <stdlib.h>
#include "compartment.h"

static const char *general_notice(void) {
	return "Notice: General Compartment";
}

Compartment *create_general(void) {
	Compartment *c = malloc(sizeof(Compartment));
	c->notice = general_notice;
	return c;
}
