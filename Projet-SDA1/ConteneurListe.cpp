/**
 * @file ConteneurListe.cpp
 * @brief Composant de conteneur d'items de capacité extensible pour les Listes
 */

#include <iostream>
#include <cassert>
using namespace std;

#include "ConteneurListe.h"

void clistes_init(ConteneurListe& cl, unsigned int capa, unsigned int p) {
	assert((capa > 0) && (p > 0));
	cl.capacite = capa;
	cl.pasExtension = p;
	cl.tab = new Liste[capa];
}

void clistes_detruire(ConteneurListe& cl) {
	delete[] cl.tab;
	cl.tab = NULL;
}

Liste clistes_lire(const ConteneurListe& cl, unsigned int i) {
	assert(i < cl.capacite);
	return cl.tab[i];
}

void clistes_ecrire(ConteneurListe& cl, unsigned int i, const Liste& it) {
	if (i >= cl.capacite) {
		unsigned int newTaille = (i + 1) * cl.pasExtension;
		Liste* newT = new Liste[newTaille];
		for (unsigned int i = 0; i < cl.capacite; ++i)
			newT[i] = cl.tab[i];
		delete[] cl.tab;
		cl.tab = newT;
		cl.capacite = newTaille;
	}
	cl.tab[i] = it;
	cl.nbListes++;
}

Liste clistes_join(ConteneurListe& cl) {

	Liste l;
	initialiser(l, 1, 2);

	for (unsigned int i = 0; i < cl.nbListes; ++i) {
		Liste tempL = clistes_lire(cl, i);
		for (unsigned int j = 0; j < tempL.nb; ++j) {
			inserer(l, l.nb, tempL.c.tab[j]);
		}
	}

	return l;

}