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

/*
* Main
*/

int main() {

	setlocale(LC_ALL, "");

	ConteneurBoggle c;
	initialiser(c, 1, 2);

	Item it;
	int nbMots = 0;

	while (true) {

		it = saisie();

		if (strcmp(it.mot, "*") == 0) {
			break;
		}

		nbMots += ecrire(c, nbMots, it);

	}

	ordonner(c, nbMots);

	for (int i = 0; i < nbMots; ++i) {
		afficher(c, i);
	}
	cout << "*" << endl;

	detruire(c);

	return 0;

}