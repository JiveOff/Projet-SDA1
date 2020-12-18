/**
 * @file Liste.cpp
 * @brief Composant de liste en mémoire dynamique et extensible
 */
 
#include <cassert> 
#include <cstring>
#include <iostream>

#include "Liste.h"

void initialiser(Liste& l, unsigned int capa, unsigned int pas) {
	assert ((capa>0) && (pas>0));
	initialiser(l.c, capa, pas);
	l.nb=0;
}
 
void detruire(Liste& l) {
	detruire(l.c);
}

unsigned int longueur(const Liste& l) {
	return l.nb;
}

Item lire(const Liste& l, unsigned int pos) {
	assert(pos<l.nb);
	return lire(l.c, pos);
}

void ecrire(Liste& l, unsigned int pos, const Item& it) {
	assert(pos<l.nb);
	ecrire(l.c, pos, it);
}	

void inserer(Liste& l, unsigned int pos, const Item& it) {
	assert(pos<=l.nb);
	for (unsigned int i=l.nb; i>pos; i--) {
		ecrire(l.c, i, lire(l.c, i-1));
	}
	ecrire(l.c, pos, it);
	l.nb++;
}

void entreeEtoile(Liste& l) {
	Item it;
	unsigned int posMots = 0;
	while (true) {
		it = saisie();
		if (strcmp(it.mot, "*") == 0) {
			break;
		}
		inserer(l, posMots, it);
	}
}

void supprimer(Liste& l, unsigned int pos) {
	assert((l.nb!=0) && (pos<l.nb));
	l.nb--;
	for (unsigned int i=pos; i<l.nb; ++i)
	   ecrire(l.c, i, lire(l.c,i+1));
}

void afficher(const Liste& t, unsigned int pos) {
	std::cout << lire(t, pos).mot << std::endl;
}

void afficherListe(const Liste& l) {
	for (unsigned int i = 0; i < l.nb; ++i) {
		afficher(l, i);
	}
	std::cout << "*" << std::endl;
}

Liste filtrer(Liste& l_1, Liste& l_2, bool (*filtre)(Liste& l, Item& it)) {
	Liste l;
	initialiser(l, 1, 2);

	for (unsigned int i = 0, pos = 0; i < l_2.nb; ++i) {
		if (filtre(l_1, l_2.c.tab[i])) {
			inserer(l, pos, l_2.c.tab[i]);
		}
	}

	return l;
}

void ordonner(Liste& l) {
	for (unsigned int j = 0; j < l.nb; ++j) {
		for (unsigned int i = 0; i < (l.nb - 1); ++i) {
			if (strcmp(l.c.tab[i].mot, l.c.tab[i + 1].mot) > 0) {
				Item tmp;
				strcpy_s(tmp.mot, l.c.tab[i].mot);
				strcpy_s(l.c.tab[i].mot, l.c.tab[i + 1].mot);
				strcpy_s(l.c.tab[i + 1].mot, tmp.mot);
			}
		}
	}
}

int getByItem(const Liste& l, const Item& it) {
	for (unsigned int i = 0; i < l.nb; ++i) {
		if (strcmp(l.c.tab[i].mot, it.mot) == 0) {
			return i;
		}
	}

	return -1; // fallback
}

Liste formeCanonique(Liste& l) {
	Liste newL;
	initialiser(newL, 1, 2);

	for (unsigned int i = 0, ins = 0; i < l.nb; ++i) {
		if (getByItem(newL, l.c.tab[i]) == -1) {
			inserer(newL, ins, l.c.tab[i]);
			ins++;
		}
	}

	ordonner(newL);

	return newL;
}