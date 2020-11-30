#pragma once

typedef struct Mot {
	char mot[31];
	int compteur = 0;
} Item;

struct ConteneurBoggle {
	int capacite;
	int pasExtension;
	Mot* tab;
};