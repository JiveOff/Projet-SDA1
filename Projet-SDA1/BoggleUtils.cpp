#include <cstring>
#include <iostream>

#include "BoggleUtils.h"

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

Liste readGrille() {

	Liste grille;
	initialiser(grille, 1, 2);

	for (unsigned int i = 0; i < 4; ++i) {
		Item m;
		std::cin >> m.mot;
		inserer(grille, )
	}

}

Grille createGrille(Liste& depart) {

	Grille grille;

	int x = 0;
	int y = 0;

	for (unsigned int x = 0; x < 4; ++x) {
		Item it = lire(depart, x);
		for (unsigned int y = 0; y < 4; ++y) {
			MotGrille m = { false, it.mot[y] };
			grille.grille[x][y] = m;
		}
	}

	for (unsigned int i = 0; i < 4; ++i) {
		for (unsigned int j = 0; j < 4; ++j) {
			std::cout << grille.grille[i][j].lettre;
		}
		std::cout << std::endl;
	}

}