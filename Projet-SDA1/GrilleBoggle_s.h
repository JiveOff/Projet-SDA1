#pragma once

typedef struct MotGrille {
	bool visite;
	char lettre;
};

struct Grille {
	MotGrille grille[4][4];
};