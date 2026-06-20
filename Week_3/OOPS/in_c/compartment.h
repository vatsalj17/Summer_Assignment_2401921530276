#ifndef COMPARTMENT_H
#define COMPARTMENT_H

typedef struct Compartment {
	const char *(*notice)(void);
} Compartment;

Compartment *create_first_class(void);
Compartment *create_ladies(void);
Compartment *create_general(void);
Compartment *create_luggage(void);

#endif
