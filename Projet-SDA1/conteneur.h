#pragma once

#include "item.h"
#include "ConteneurBoggle.h"

void initialiser(ConteneurBoggle& t, int capacite, int pas);
void detruire(ConteneurBoggle& t);
Item lire(const ConteneurBoggle& t, int pos);
bool ecrire(ConteneurBoggle& t, int pos, const Item& it);
void afficher(const ConteneurBoggle& t, int pos);
void ordonner(ConteneurBoggle& t);
void filtrer(ConteneurBoggle& c_1, ConteneurBoggle& c_2, bool (*filtre)(ConteneurBoggle& t, Item& it));
int getByItem(const ConteneurBoggle& t, const Item& it);

// IO

Item saisie();