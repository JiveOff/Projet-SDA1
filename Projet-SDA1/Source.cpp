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
		return (getByItem(l, it) > -1);
	};

	Liste l_filtre = filtrer(l_1, l_2, filtre);

	detruire(l_1);
	detruire(l_2);

	Liste l_canonique = formeCanonique(l_filtre);

	detruire(l_filtre);

	afficherListe(l_canonique);

	detruire(l_canonique);

}

void exo5() {
	cout << "cinquieme pgm" << endl;
}

void exo6() {
	cout << "sixieme pgm" << endl;
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