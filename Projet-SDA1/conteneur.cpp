#include <cassert>
#include <iostream>

#include "conteneur.h"

void initialiser(ConteneurBoggle& t, int capacite, int pas) {

	assert(capacite > 0 && pas > 0);

	t.capacite = capacite;
	t.pasExtension = pas;

	t.tab = new Item[t.capacite];

}

void detruire(ConteneurBoggle& t) {
	delete[] t.tab;
	t.capacite = 0;
}

Item lire(const ConteneurBoggle& t, int pos) {
	assert(pos < t.capacite);
	return t.tab[pos];
}

void ecrire(ConteneurBoggle& t, int pos, const Item& it) {

	if (pos >= t.capacite) {

		int newTaille = (pos + 1) * t.pasExtension;

		Item* newT = new Item[newTaille];

		for (int i = 0; i < t.capacite; ++i)
			newT[i] = t.tab[i];

		delete[] t.tab;

		t.tab = newT;
		t.capacite = newTaille;

	}

	t.tab[pos] = it;

}

void afficher(const ConteneurBoggle& t, int pos) {
	std::cout << lire(t, pos).mot << std::endl;
}

ConteneurBoggle cleanDuplicates(ConteneurBoggle& t, int nbMots) {

	ConteneurBoggle c;
	initialiser(c, 1, 2);

	Item it;
	int nbRetotal = 0;

	for (int j = 0; j < nbMots; ++j) {
		for (int i = 0; i < (nbMots - 1); ++i) {
			if (strcmp(t.tab[i].mot, t.tab[j + 1].mot) != 0) {
				ecrire(c, nbRetotal, t.tab[i]);
			}
		}
	}
}

void ordonner(ConteneurBoggle& t, int nbMots) {
	for (int j = 0; j < nbMots; ++j) {
		for (int i = 0; i < (nbMots - 1); ++i) {
			if (strcmp(t.tab[i].mot, t.tab[i + 1].mot) > 0) {
				Item tmp;
				strcpy_s(tmp.mot, t.tab[i].mot);
				strcpy_s(t.tab[i].mot, t.tab[i + 1].mot);
				strcpy_s(t.tab[i + 1].mot, tmp.mot);
			}
		}
	}
}

int getByItem(const ConteneurBoggle& t, const Item& it) {
	for (int i = 0; i < t.capacite; ++i) {
		if (strcmp(t.tab[i].mot, it.mot) == 0) {
			return i;
		}
	}

	return -1; // fallback
}

Item saisie() {
	Item it;
	std::cin >> it.mot;
	return it;
}