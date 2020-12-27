#pragma once

/**
 * @file GrilleBoggle_s.h
 * @brief Structure de la grille de boggle.
 */

typedef struct LettreGrille {
	bool visite;
	char lettre;
} LettreGrille;

struct PositionGrille {
	int x = 0;
	int y = 0;
};

struct Grille {
	LettreGrille grille[4][4];
};