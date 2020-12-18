#include <cstring>
#include "Liste.h"

unsigned int calculPoint(Item it) {

	unsigned int motLength = (unsigned int)strlen(it.mot);

	if (motLength <= 2) {
		return 0;
	}
	else if (motLength <= 4) {
		return 1;
	}
	else if (motLength <= 5) {
		return 2;
	}
	else if (motLength <= 6) {
		return 3;
	}
	else if (motLength <= 7) {
		return 5;
	}
	else if (motLength >= 8) {
		return 11;
	}
	else {
		return 0;
	}
}

unsigned int calculPointGlobal(Liste& l) {

	unsigned int total = 0;

	for (unsigned int i = 0; i < l.nb; ++i) {
		total += calculPoint(lire(l, i));
	}

	return total;
}