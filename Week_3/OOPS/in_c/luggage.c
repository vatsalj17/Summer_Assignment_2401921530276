#include <stdlib.h>
#include "compartment.h"

static const char *luggage_notice(void) {
	return "Notice: Luggage Compartment";
}

Compartment *create_luggage(void) {
	Compartment *c = malloc(sizeof(Compartment));
	c->notice = luggage_notice;
	return c;
}
