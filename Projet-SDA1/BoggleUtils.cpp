/**
 * @file BoggleUtils.h
 * @brief Utilitaires pour la mise en oeuvre du boggle.
 */

#include <cstring>
#include <iostream>

#include "BoggleUtils.h"

unsigned int calculPoint(Item it) {

	unsigned int motLength = (unsigned int)strlen(it.mot);

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
	else {
		return 0;
	}
}

unsigned int calculPointGlobal(Liste& l) {

	unsigned int total = 0;

	for (unsigned int i = 0; i < l.nb; ++i) {
		total += calculPoint(lire(l, i));
	}

	return total;
}

Liste readGrille() {

	Liste grille;
	initialiser(grille, 1, 2);

	for (unsigned int i = 0; i < 4; ++i) {
		inserer(grille, grille.nb, saisie());
	}

	return grille;

}

Grille createGrille(Liste& depart) {

	Grille grille;
	PositionGrille pos;

	for (pos.x = 0; pos.x < 4; ++pos.x) {
		Item it = lire(depart, pos.x);
		for (pos.y = 0; pos.y < 4; ++pos.y) {
			LettreGrille m = { false, it.mot[pos.y] };
			grille.grille[pos.x][pos.y] = m;
		}
	}

	detruire(depart);

	return grille;

}

void afficherGrille(const Grille& grille) {

	PositionGrille pos;
	for (pos.x = 0; pos.x < 4; ++pos.x) {
		for (pos.y = 0; pos.y < 4; ++pos.y) {
			std::cout << grille.grille[pos.x][pos.y].lettre;
		}
		std::cout << std::endl;
	}

}

bool rechercherMot(Grille& grille, Item& it) {

	PositionGrille pos;
	for (pos.x = 0; pos.x < 4; ++pos.x) {
		for (pos.y = 0; pos.y < 4; ++pos.y) {
			grille.grille[pos.x][pos.y].visite = false;
		}
	}

	pos = { 0, 0 };

	for (pos.x = 0; pos.x < 4; ++pos.x) {
		for (pos.y = 0; pos.y < 4; ++pos.y) {
			if (sousRecherche(grille, it, 0, pos)) {
				//std::cout << "Passed wtf main";
				return true;
			}
		}
	}

	return false;

}

bool checkLimites(PositionGrille& coord) {
	return (coord.x > -1 && coord.y > -1 && coord.x < 4 && coord.y < 4);
}

bool sousRecherche(Grille& grille, Item& it, int pos, PositionGrille& coord) {

	//std::cout << it.mot << std::endl;

	if (pos >= strlen(it.mot)) {
		//std::cout << "test1" << std::endl;
		return true;
	}

	if (!checkLimites(coord)) {
		//std::cout << "test2" << std::endl;
		return false;
	}
		

	if (grille.grille[coord.x][coord.y].lettre != it.mot[pos]) {
		//std::cout << "test3" << std::endl;
		return false;
	}

	if (grille.grille[coord.x][coord.y].visite == true) {
		//std::cout << "test4" << std::endl;
		return false;
	}

	//std::cout << "Passed at x: " << coord.x << " y: "<< coord.y << std::endl;

	grille.grille[coord.x][coord.y].visite = true;

	PositionGrille pCoord[8];
	PositionGrille tempCoord;
	unsigned int nbCoord = 0;

	tempCoord = { coord.x - 1, coord.y - 1 };
	if (checkLimites(tempCoord)) {
		pCoord[nbCoord++] = { tempCoord.x, tempCoord.y };
	}

	tempCoord = { coord.x - 1, coord.y };
	if (checkLimites(tempCoord)) {
		pCoord[nbCoord++] = { tempCoord.x, tempCoord.y };
	}

	tempCoord = { coord.x - 1, coord.y + 1 };
	if (checkLimites(tempCoord)) {
		pCoord[nbCoord++] = { tempCoord.x, tempCoord.y };
	}

	tempCoord = { coord.x, coord.y - 1 };
	if (checkLimites(tempCoord)) {
		pCoord[nbCoord++] = { tempCoord.x, tempCoord.y };
	}

	tempCoord = { coord.x, coord.y + 1 };
	if (checkLimites(tempCoord)) {
		pCoord[nbCoord++] = { tempCoord.x, tempCoord.y };
	}

	tempCoord = { coord.x + 1, coord.y - 1 };
	if (checkLimites(tempCoord)) {
		pCoord[nbCoord++] = { tempCoord.x, tempCoord.y };
	}

	tempCoord = { coord.x + 1, coord.y };
	if (checkLimites(tempCoord)) {
		pCoord[nbCoord++] = { tempCoord.x, tempCoord.y };
	}

	tempCoord = { coord.x + 1, coord.y + 1 };
	if (checkLimites(tempCoord)) {
		pCoord[nbCoord++] = { tempCoord.x, tempCoord.y };
	}

	for (unsigned int i = 0; i < nbCoord; ++i) {
		if (sousRecherche(grille, it, pos + 1, pCoord[i])) {
			//std::cout << "Passed wtf";
			return true;
		}
	}

	grille.grille[coord.x][coord.y].visite = false;
	return false;

}