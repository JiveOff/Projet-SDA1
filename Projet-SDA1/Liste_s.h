#pragma once

/**
 * @file ConteneurListe_s.h
 * @brief Structure d'une liste.
 */

#include "ConteneurTDE.h"

struct Liste {
	/// Conteneur m�morisant les �l�ments de la liste.
	ConteneurTDE c;
	/// Nombre d'�l�ments stock�s dans la liste.
	unsigned int nb;
};