#include <cassert>
#include <iostream>

#include "boggle-utils.h"

Item saisie() {
	Item it;
	std::cin >> it.mot;
	return it;
}

unsigned int calculPoint(const Item it) {

	unsigned int motLength = strlen(it.mot);

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

unsigned int calculPointConteneur(const ConteneurBoggle& t, unsigned int nbMots) {

	unsigned int total = 0;

	for (int i = 0; i < nbMots; ++i) {
		total += calculPoint(lire(t, i));
	}

	return total;
}