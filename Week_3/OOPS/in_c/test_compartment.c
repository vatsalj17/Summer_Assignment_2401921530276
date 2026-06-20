#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "compartment.h"

int main(void) {
	Compartment *compartments[10];
	srand(time(0));

	for (int i = 0; i < 10; i++) {
		int type = (rand() % 4) + 1;
		if (type == 1) {
			compartments[i] = create_luggage();
		} else if (type == 2) {
			compartments[i] = create_ladies();
		} else if (type == 3) {
			compartments[i] = create_general();
		} else {
			compartments[i] = create_first_class();
		}
	}

	for (int i = 0; i < 10; i++) {
		printf("%s\n", compartments[i]->notice());
	}

	for (int i = 0; i < 10; i++) {
		free(compartments[i]);
	}
	return 0;
}
