#include <stdlib.h>
#include "music/string/veena.h"
#include "music/wind/saxophone.h"

int main(void) {
	Veena *veena = createVeena();
	veena->base.play();

	Saxophone *saxophone = createSaxophone();
	saxophone->base.play();

	Playable *playable = (Playable *)createVeena();
	playable->play();
    free(playable);

	playable = (Playable *)createSaxophone();
	playable->play();

	free(veena);
	free(saxophone);
	free(playable);

	return 0;
}
