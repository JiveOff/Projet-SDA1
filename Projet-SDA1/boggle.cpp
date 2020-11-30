#include <iostream>

#include "boggle.h"
#include "conteneur.h"

int calculPoint(const Item it) {

	int motLength = strlen(it.mot);

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
}

int calculPointConteneur(const ConteneurBoggle& t, int nbMots) {

	int total = 0;

	for (int i = 0; i < nbMots; ++i) {
		total += calculPoint(lire(t, i));
	}

	return total;
}