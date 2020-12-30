#pragma once

/**
 * @file BoggleUtils.h
 * @brief Utilitaires pour la mise en oeuvre du boggle.
 */

#include "Liste.h"

/**
  * @brief D�finition du type structure pour une seule lettre de la grille.
  */
typedef struct LettreGrille {
	bool visite;
	char lettre;
} LettreGrille;

/**
  * @brief Structure permettant de d�clarer une position dans la grille.
  */
struct PositionGrille {
	int x = 0;
	int y = 0;
};

/*
* @brief Structure pr�sentant un tableau deux dimensions pour la grille.
*/
struct Grille {
	LettreGrille grille[4][4];
};

/**
 * @brief Calcul des points "boggle" d'un seul item.
 * @param[in] it L'item.
 * @return Le nombre de points.
 */
unsigned int calculPoint(const Item it);

/**
 * @brief Calcul des points "boggle" d'une liste enti�re.
 * @param[in] l La liste.
 * @return Le nombre de points.
 */
unsigned int calculPointGlobal(const Liste& l);

/**
 * @brief Cr�ation d'une grille avec une liste de d�part (4x4) tap�e au clavier.
 * @return Une grille (un tableau deux dimensions contenu dans la structure).
 */
Grille createGrille();

/**
 * @brief V�rifie si une position est bien dans les limites d'une grille boggle.
 * @param[in] coord La position d'une grille.
 * @return Un bool�en: 1 indique que la position est dans les limites, sinon 0.
 */
bool checkLimites(const PositionGrille& coord);

/**
 * @brief Recherche un Item (mot) dans une grille donn�e.
 * @param[in,out] grille La grille de lettres.
 * @param[in] it L'item (mot) � rechercher dans la grille donn�e.
 * @return Une grille (un tableau deux dimensions contenu dans la structure).
 */
bool rechercherMot(Grille& grille, Item& it);

/**
 * @brief Fonction de sous-recherche utilis�e dans rechercheMot.
 * @param[in,out] grille La grille de lettres.
 * @param[in] it L'item (mot) � rechercher dans la grille donn�e.
 * @return Une grille (un tableau deux dimensions contenu dans la structure).
 */
bool sousRecherche(Grille& grille, Item& it, int pos, PositionGrille& coord);