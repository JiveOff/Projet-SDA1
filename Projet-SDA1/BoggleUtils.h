#pragma once

/**
 * @file BoggleUtils.h
 * @brief Utilitaires pour la mise en oeuvre du boggle.
 */

#include "GrilleBoggle_s.h"
#include "Liste.h"

unsigned int calculPointGlobal(Liste& l);

unsigned int calculPoint(Item it);

Liste readGrille();

Grille createGrille(Liste& depart);

void afficherGrille(const Grille& grille);

bool rechercherMot(Grille& grille, Item& it);

bool checkLimites(PositionGrille& coord);

bool sousRecherche(Grille& grille, Item& it, int pos, PositionGrille& coord);