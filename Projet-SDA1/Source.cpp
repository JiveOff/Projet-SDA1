/*
* Projet-SDA1 - Sprint 2
*
* @author Antoine Banha <antoine@jiveoff.fr>
* @author Rayan Atrouni <rayan.atrouni@etu.u-paris.fr>
*/

#include <iostream>
#include <cassert>
#include <clocale>
#include <cstring>

#include "conteneur.h"
#include "boggle.h"

using namespace std;

bool filtre(ConteneurBoggle& t, Item& it) {
	return (getByItem(t, it) > -1);
}

/*
* Main
*/

int main() {

	setlocale(LC_ALL, "");

	ConteneurBoggle c_1;
	initialiser(c_1, 1, 2);

	Item it;

	while (true) {

		it = saisie();

		if (strcmp(it.mot, "*") == 0) {
			break;
		}

		c_1.nbMots += ecrire(c_1, c_1.nbMots, it);

	}

	ordonner(c_1);

	ConteneurBoggle c_2;
	initialiser(c_2, 1, 2);

	while (true) {

		it = saisie();

		if (strcmp(it.mot, "*") == 0) {
			break;
		}

		c_2.nbMots += ecrire(c_2, c_2.nbMots, it);

	}

	ordonner(c_2);
	
	filtrer(c_1, c_2, &filtre);

	for (int i = 0; i < c_2.nbMots; ++i) {
		afficher(c_2, i);
	}
	cout << "*" << endl;

	detruire(c_1);
	detruire(c_2);

	return 0;

}