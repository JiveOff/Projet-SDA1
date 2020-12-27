#pragma once

/**
 * @file ConteneurListe_s.h
 * @brief Structure du conteneur de listes.
 */

#include "Liste.h"

/** @brief Conteneur d'items alloués en mémoire dynamique
 *  de capacité extensible suivant un pas d'extension.
 */
struct ConteneurListe {
	/// Capacité du conteneur (>0).
	unsigned int capacite;
	/// Pas d'extension du conteneur (>0).
	unsigned int pasExtension;
	/// Conteneur alloué en mémoire dynamique.
	Liste* tab;
	/// Nombre de listes.
	unsigned int nbListes = 0;
};