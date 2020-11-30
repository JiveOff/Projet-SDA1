#pragma once

typedef struct Mot {
	char mot[31];
} Item;

struct ConteneurBoggle {
	int capacite;
	int pasExtension;
	Mot* tab;
};