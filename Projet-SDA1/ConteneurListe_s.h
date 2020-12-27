#pragma once

/**
 * @file ConteneurListe_s.h
 * @brief Structure du conteneur de listes.
 */

#include "Liste.h"

/** @brief Conteneur d'items allou�s en m�moire dynamique
 *  de capacit� extensible suivant un pas d'extension.
 */
struct ConteneurListe {
	/// Capacit� du conteneur (>0).
	unsigned int capacite;
	/// Pas d'extension du conteneur (>0).
	unsigned int pasExtension;
	/// Conteneur allou� en m�moire dynamique.
	Liste* tab;
	/// Nombre de listes.
	unsigned int nbListes = 0;
};