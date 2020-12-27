/*
* Projet-SDA1
*
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
* Main
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

	//Liste l_1 = formeCanonique(tempL_1);
	//detruire(tempL_1);

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

	for (unsigned int i = 0; i < l.nb; ++i) {
		if (occurences(l, l.c.tab[i]) >= 2) {
			inserer(lFinal, lFinal.nb, l.c.tab[i]);
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
	
	Liste depart = readGrille();
	Grille grille = createGrille(depart);

	Liste l;
	initialiser(l, 100, 200);

	entreeEtoile(l);

	//afficherGrille(grille);

	for (unsigned int i = 0; i < l.nb; ++i) {
		if (rechercherMot(grille, l.c.tab[i])) {
			afficher(l, i);
		}
	}

	std::cout << "*";

}

int main() {

	setlocale(LC_ALL, "");

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