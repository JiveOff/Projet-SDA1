/**
 * @file ConteneurTDE.cpp
 * @brief Composant de conteneur d'items de capacité extensible
 */

#include <cassert>
using namespace std;

#include "ConteneurTDE.h"

void tde_initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p) {
	assert((capa > 0) && (p > 0));
	c.capacite = capa;
	c.pasExtension = p;
	c.tab = new Item[capa];
}

void tde_detruire(ConteneurTDE& c) {
	delete[] c.tab;
	c.tab = NULL;
}

Item tde_lire(const ConteneurTDE& c, unsigned int i) {
	assert(i < c.capacite);
	return c.tab[i];
}

void tde_ecrire(ConteneurTDE& c, unsigned int i, const Item& it) {
	if (i >= c.capacite) {
		unsigned int newTaille = (i + 1) * c.pasExtension;
		Item* newT = new Item[newTaille];
		for (unsigned int i = 0; i < c.capacite; ++i)
			newT[i] = c.tab[i];
		delete[] c.tab;
		c.tab = newT;
		c.capacite = newTaille;
	}
	c.tab[i] = it;
}
