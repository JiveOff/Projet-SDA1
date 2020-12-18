#pragma once

#include "ConteneurTDE.h"

struct Liste {
	/// Conteneur mémorisant les éléments de la liste.
	ConteneurTDE c;
	/// Nombre d'éléments stockés dans la liste.
	unsigned int nb;
};