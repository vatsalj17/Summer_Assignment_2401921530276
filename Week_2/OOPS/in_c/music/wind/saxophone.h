#ifndef SAXOPHONE_H
#define SAXOPHONE_H

#include "music/playable.h"

typedef struct {
	Playable base;
} Saxophone;

Saxophone *createSaxophone();

#endif
