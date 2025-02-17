#pragma once

/**
 * @file ConteneurListe.h
 * @brief Composant d'un conteneur de listes � capacit� extensible.
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

 /**
  * @brief Initialise un conteneur d'items.
  * Allocation en m�moire dynamique du conteneur d'items
  * de capacit� (capa) extensible par pas d'extension (p).
  * @see detruire, pour sa d�sallocation en fin d'utilisation.
  * @param[out] c Le conteneur d'items.
  * @param [in] capa Capacit� du conteneur.
  * @param [in] p Pas d'extension de capacit�.
  * @pre capa > 0 et p > 0.
  */
void clistes_init(ConteneurListe& cl, unsigned int capa, unsigned int p);

/**
 * @brief D�salloue un conteneur d'items en m�moire dynamique.
 * @see initialiser.
 * @param[in,out] c Le conteneur d'items.
 */
void clistes_detruire(ConteneurListe& cl);

/**
 * @brief Lecture d'un item d'un conteneur d'items.
 * @param[in] c Le conteneur d'items.
 * @param[in] i La position de l'item dans le conteneur.
 * @return L'item � la position i.
 * @pre i < c.capacite
 */
Liste clistes_lire(const ConteneurListe& cl, unsigned int i);

/**
 * @brief Ecrire un item dans un conteneur d'items.
 * @param[in,out] c Le conteneur d'items.
 * @param[in] i La position o� ajouter/modifier l'item.
 * @param[in] it L'item � �crire.
 */
void clistes_ecrire(ConteneurListe& cl, unsigned int i, const Liste& l);

/**
 * @brief Rassemble tous les �l�ments de listes en une seule.
 * @param[in,out] c Le conteneur de listes.
 * @return Une liste contenant tous les items des listes du conteneur de listes.
 */
Liste clistes_join(const ConteneurListe& cl);