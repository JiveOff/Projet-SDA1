/*
* Projet-SDA1 - Sprint 1
* 
* @author Antoine Banha <antoine@jiveoff.fr>
* @author Rayan Atrouni <rayan.atrouni@etu.u-paris.fr>
*/

#include <iostream>
#include <cassert>
#include <clocale>
#include <cstring>

using namespace std;

struct Mot {
	char mot[31];
};

struct ConteneurBoggle {
	unsigned int capacite;
	unsigned int pasExtension;
	Mot* tab;
};

typedef Mot Item;

void initialiser(ConteneurBoggle& t, unsigned int capacite, unsigned int pas);
void detruire(ConteneurBoggle& t);
Mot lire(const ConteneurBoggle& t, unsigned int pos);
void ecrire(ConteneurBoggle& t, unsigned int pos, const Item& it);

/*
* Fonctions utilitaires
*/

Item saisie() {
	Item it;
	cin >> it.mot;
	return it;
}

unsigned int calculPoint(Item it) {

	unsigned int motLength = strlen(it.mot);

	if (motLength <= 2) {
		return 0;
	}
	else if (motLength <= 4) {
		return 1;
	}
	else if (motLength <= 5) {
		return 2;
	}
	else if (motLength <= 6) {
		return 3;
	}
	else if (motLength <= 7) {
		return 5;
	}
	else if (motLength >= 8) {
		return 11;
	}
}

unsigned int calculPointConteneur(ConteneurBoggle& t, unsigned int nbMots) {

	unsigned int total = 0;

	for (int i = 0; i < nbMots; ++i) {
		total += calculPoint(lire(t, i));
	}

	return total;
}

/*
* Fonctions de gestion du conteneur
*/

void initialiser(ConteneurBoggle& t, unsigned int capacite, unsigned int pas) {

	assert(capacite > 0 && pas > 0);

	t.capacite = capacite;
	t.pasExtension = pas;

	t.tab = new Item[t.capacite];

	cout << "Allocation initiale de " << capacite * sizeof(Item) << " octets (" << capacite << " item(s))" << endl;

}

void detruire(ConteneurBoggle& t) {
	delete[] t.tab;
	t.capacite = 0;
}

Item lire(const ConteneurBoggle& t, unsigned int pos) {
	assert(pos < t.capacite);
	return t.tab[pos];
}

void ecrire(ConteneurBoggle& t, unsigned int pos, const Item& it) {
	
	if (pos >= t.capacite) {

		unsigned int newTaille = (pos + 1) * t.pasExtension;

		Item* newT = new Item[newTaille];

		for (int i = 0; i < t.capacite; ++i)
			newT[i] = t.tab[i];

		delete[] t.tab;

		t.tab = newT;
		t.capacite = newTaille;

		cout << "Extension - Allocaton/Réallocation de " << newTaille * sizeof(Item) << " octets (" << newTaille << " items)." << endl;

	}

	t.tab[pos] = it;

}

/*
* Main
*/

int main() {

	setlocale(LC_ALL, "");

	ConteneurBoggle c;
	initialiser(c, 1, 2);

	Item it;
	unsigned int nbMots = 0;

	while (true) {

		it = saisie();
		
		if (strcmp(it.mot, "*") == 0) {
			cout << calculPointConteneur(c, nbMots);
			break;
		}

		ecrire(c, nbMots, it);
		nbMots++;

	}

	detruire(c);

	return 0;

}