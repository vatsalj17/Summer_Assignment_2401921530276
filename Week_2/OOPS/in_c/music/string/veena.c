#include <stdio.h>
#include <stdlib.h>
#include "veena.h"

void veena_play() {
	printf("Playing Veena\n");
}

Veena *createVeena() {
	Veena *veena = malloc(sizeof(Veena));
	veena->base.play = veena_play;
	return veena;
}
