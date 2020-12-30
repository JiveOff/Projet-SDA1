#pragma once

/**
 * @file BoggleUtils.h
 * @brief Utilitaires pour la mise en oeuvre du boggle.
 */

#include "Liste.h"

/**
  * @brief Définition du type structure pour une seule lettre de la grille.
  */
typedef struct LettreGrille {
	bool visite;
	char lettre;
} LettreGrille;

/**
  * @brief Structure permettant de déclarer une position dans la grille.
  */
struct PositionGrille {
	int x = 0;
	int y = 0;
};

/*
* @brief Structure présentant un tableau deux dimensions pour la grille.
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
 * @brief Calcul des points "boggle" d'une liste entière.
 * @param[in] l La liste.
 * @return Le nombre de points.
 */
unsigned int calculPointGlobal(const Liste& l);

/**
 * @brief Création d'une grille avec une liste de départ (4x4) tapée au clavier.
 * @return Une grille (un tableau deux dimensions contenu dans la structure).
 */
Grille createGrille();

/**
 * @brief Vérifie si une position est bien dans les limites d'une grille boggle.
 * @param[in] coord La position d'une grille.
 * @return Un booléen: 1 indique que la position est dans les limites, sinon 0.
 */
bool checkLimites(const PositionGrille& coord);

/**
 * @brief Recherche un Item (mot) dans une grille donnée.
 * @param[in,out] grille La grille de lettres.
 * @param[in] it L'item (mot) à rechercher dans la grille donnée.
 * @return Une grille (un tableau deux dimensions contenu dans la structure).
 */
bool rechercherMot(Grille& grille, Item& it);

/**
 * @brief Fonction de sous-recherche utilisée dans rechercheMot.
 * @param[in,out] grille La grille de lettres.
 * @param[in] it L'item (mot) à rechercher dans la grille donnée.
 * @return Une grille (un tableau deux dimensions contenu dans la structure).
 */
bool sousRecherche(Grille& grille, Item& it, int pos, PositionGrille& coord);