#ifndef VEENA_H
#define VEENA_H

#include "music/playable.h"

typedef struct {
	Playable base;
} Veena;

Veena *createVeena();

#endif
