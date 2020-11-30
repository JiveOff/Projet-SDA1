#pragma once

#include "conteneur.h"

struct ConteneurBoggle {
	unsigned int capacite;
	unsigned int pasExtension;
	Mot* tab;
};

Item saisie();
unsigned int calculPoint(const Item it);
unsigned int calculPointConteneur(const ConteneurBoggle& t, unsigned int nbMots);