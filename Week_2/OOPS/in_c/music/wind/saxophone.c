#include <stdio.h>
#include <stdlib.h>
#include "saxophone.h"

void saxophone_play() {
	printf("Playing Saxophone\n");
}

Saxophone *createSaxophone() {
	Saxophone *saxophone = malloc(sizeof(Saxophone));
	saxophone->base.play = saxophone_play;
	return saxophone;
}
