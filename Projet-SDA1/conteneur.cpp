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

bool ecrire(ConteneurBoggle& t, int pos, const Item& it) {
	
	int indice = getByItem(t, it);

	if (indice > -1) {
		t.tab[indice].compteur++;
		return false;
	}

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
	t.tab[pos].compteur = 1;
	return true;

}

void afficher(const ConteneurBoggle& t, int pos) {
	if(lire(t, pos).compteur > 0) std::cout << lire(t, pos).mot << std::endl;
}

void ordonner(ConteneurBoggle& t) {
	for (int j = 0; j < t.nbMots; ++j) {
		for (int i = 0; i < (t.nbMots - 1); ++i) {
			if (strcmp(t.tab[i].mot, t.tab[i + 1].mot) > 0) {
				Item tmp;
				strcpy_s(tmp.mot, t.tab[i].mot);
				strcpy_s(t.tab[i].mot, t.tab[i + 1].mot);
				strcpy_s(t.tab[i + 1].mot, tmp.mot);
			}
		}
	}
}

void filtrer(ConteneurBoggle& c_1, ConteneurBoggle& c_2, bool (*filtre)(ConteneurBoggle& t, Item& it)) {
	for (int i = 0; i < c_2.nbMots; ++i) {
		if (!filtre(c_1, c_2.tab[i])) {
			c_2.tab[i].compteur = 0;
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