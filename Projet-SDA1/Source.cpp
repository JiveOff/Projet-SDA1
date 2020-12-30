/*
* Projet de SDA
* @file Source.cpp
* @author Antoine Banha <antoine@jiveoff.fr>
* @author Rayan Atrouni <rayan.atrouni@etu.u-paris.fr>
*/

#include <iostream>
#include <cassert>
#include <clocale>
#include <cstring>

#include "ConteneurListe.h"

#include "Liste.h"
#include "BoggleUtils.h"

using namespace std;

/*
* Tests unitaires
*/

void tests() {

	Liste l_1;
	initialiser(l_1, 1, 2);

	for (int i = 0; i < 10; ++i) {
		Item it;
		sprintf_s(it.mot, "test%d", i);
		inserer(l_1, longueur(l_1), it);
	}

	assert(longueur(l_1) == 10);
	assert(strcmp(lire(l_1, 3).mot, "test3") == 0);
	
	Item it_test;
	strcpy_s(it_test.mot, "test2");
	assert(getByItem(l_1, it_test) == 2);

	Liste l_2;

	initialiser(l_2, 1, 2);

	Item it;
	strcpy_s(it.mot, "test");

	for (int i = 0; i < 5; ++i) {
		inserer(l_2, longueur(l_2), it);
	}
	for (int i = 0; i < 4; ++i) {
		Item it_2;
		sprintf_s(it_2.mot, "test%d", i);
		inserer(l_2, longueur(l_2), it_2);
	}

	assert(occurences(l_2, it) == 5);

	auto filtre = [](Liste& l, Item& it) {
		int index = getByItem(l, it);
		return (index > -1);
	};

	assert(longueur(filtrer(l_1, l_2, filtre)) == 4);

}

/*
* Structure imposée
*/

void exo1() {

	Liste l;
	initialiser(l, 1, 2);

	entreeEtoile(l);

	cout << calculPointGlobal(l);

	detruire(l);

}

void exo2() {
	
	Liste l;
	initialiser(l, 1, 2);

	entreeEtoile(l);

	Liste newL = formeCanonique(l);
	detruire(l);

	afficherListe(newL);

	detruire(newL);

}

void exo3() {
	
	Liste tempL_1;
	initialiser(tempL_1, 1, 2);

	entreeEtoile(tempL_1);

	Liste l_1 = formeCanonique(tempL_1);
	detruire(tempL_1);

	Liste tempL_2;
	initialiser(tempL_2, 1, 2);

	entreeEtoile(tempL_2);

	Liste l_2 = formeCanonique(tempL_2);
	detruire(tempL_2);

	auto filtre = [](Liste& l, Item& it) {
		return (getByItem(l, it) == -1);
	};

	Liste l_filtre = filtrer(l_1, l_2, filtre);

	detruire(l_1);
	detruire(l_2);

	Liste l_canonique = formeCanonique(l_filtre);

	detruire(l_filtre);

	afficherListe(l_canonique);

	detruire(l_canonique);

}

void exo4() {
	
	Liste tempL_1;
	initialiser(tempL_1, 100, 200);

	entreeEtoile(tempL_1);

	Liste tempL_2;
	initialiser(tempL_2, 1, 2);

	entreeEtoile(tempL_2);

	Liste l_2 = formeCanonique(tempL_2);
	detruire(tempL_2);

	auto filtre = [](Liste& l, Item& it) {
		int index = getByItem(l, it);
		return (index > -1);
	};

	Liste l_filtre = filtrer(tempL_1, l_2, filtre);

	detruire(tempL_1);
	detruire(l_2);

	Liste l_canonique = formeCanonique(l_filtre);

	detruire(l_filtre);

	afficherListe(l_canonique);

	detruire(l_canonique);

}

void exo5() {
	
	ConteneurListe cl;
	clistes_init(cl, 1, 2);

	while (true) {

		Liste tempL;
		initialiser(tempL, 1, 2);

		entreeEtoile(tempL);

		if (longueur(tempL) == 0) {
			detruire(tempL);
			break;
		}

		Liste lCanonique = formeCanonique(tempL);
		detruire(tempL);

		clistes_ecrire(cl, cl.nbListes, lCanonique);

	}

	Liste l = clistes_join(cl);

	Liste lFinal;
	initialiser(lFinal, 1, 2);

	for (unsigned int i = 0; i < longueur(l); ++i) {
		if (occurences(l, l.c.tab[i]) >= 2) {
			inserer(lFinal, longueur(lFinal), l.c.tab[i]);
		}
	}

	detruire(l);

	Liste lCanonique = formeCanonique(lFinal);
	detruire(lFinal);

	afficherListe(lCanonique);

	detruire(lCanonique);

	clistes_detruire(cl);

}

void exo6() {

	Grille grille = createGrille();

	Liste l;
	initialiser(l, 100, 200);

	entreeEtoile(l);

	for (unsigned int i = 0; i < longueur(l); ++i) {
		if (rechercherMot(grille, l.c.tab[i])) {
			afficher(l, i);
		}
	}

	std::cout << "*";

}

int main() {

	setlocale(LC_ALL, "");

	tests();

	int num;
	cin >> num;
	switch (num) {
		case 1:
			exo1(); break;
		case 2:
			exo2(); break;
		case 3:
			exo3(); break;
		case 4:
			exo4(); break;
		case 5:
			exo5(); break;
		case 6:
			exo6(); break;
	}

	return 0;
}