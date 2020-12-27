/**
 * @file BoggleUtils.h
 * @brief Utilitaires pour la mise en oeuvre du boggle.
 */

#include <cstring>
#include <iostream>

#include "BoggleUtils.h"

unsigned int calculPoint(const Item it) {

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

unsigned int calculPointGlobal(const Liste& l) {

	unsigned int total = 0;

	for (unsigned int i = 0; i < l.nb; ++i) {
		total += calculPoint(lire(l, i));
	}

	return total;
}

Grille createGrille() {

	Liste depart;
	Grille grille;
	PositionGrille pos;

	initialiser(depart, 1, 2);

	for (unsigned int i = 0; i < 4; ++i) {
		inserer(depart, depart.nb, saisie());
	}

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
				return true;
			}
		}
	}

	return false;

}

bool checkLimites(const PositionGrille& coord) {
	return (coord.x > -1 && coord.y > -1 && coord.x < 4 && coord.y < 4);
}

bool sousRecherche(Grille& grille, Item& it, int pos, PositionGrille& coord) {

	if (pos >= strlen(it.mot)) {
		return true;
	}

	if (!checkLimites(coord)) {
		return false;
	}
		

	if (grille.grille[coord.x][coord.y].lettre != it.mot[pos]) {
		return false;
	}

	if (grille.grille[coord.x][coord.y].visite == true) {
		return false;
	}

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
			return true;
		}
	}

	grille.grille[coord.x][coord.y].visite = false;
	return false;

}