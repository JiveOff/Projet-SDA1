#pragma once

/**
 * @file ConteneurListe.h
 * @brief Composant d'un conteneur de listes à capacité extensible.
 */

#include "Liste.h"

 /** @brief Conteneur d'items alloués en mémoire dynamique
  *  de capacité extensible suivant un pas d'extension.
  */
struct ConteneurListe {
	/// Capacité du conteneur (>0).
	unsigned int capacite;
	/// Pas d'extension du conteneur (>0).
	unsigned int pasExtension;
	/// Conteneur alloué en mémoire dynamique.
	Liste* tab;
	/// Nombre de listes.
	unsigned int nbListes = 0;
};

 /**
  * @brief Initialise un conteneur d'items.
  * Allocation en mémoire dynamique du conteneur d'items
  * de capacité (capa) extensible par pas d'extension (p).
  * @see detruire, pour sa désallocation en fin d'utilisation.
  * @param[out] c Le conteneur d'items.
  * @param [in] capa Capacité du conteneur.
  * @param [in] p Pas d'extension de capacité.
  * @pre capa > 0 et p > 0.
  */
void clistes_init(ConteneurListe& cl, unsigned int capa, unsigned int p);

/**
 * @brief Désalloue un conteneur d'items en mémoire dynamique.
 * @see initialiser.
 * @param[in,out] c Le conteneur d'items.
 */
void clistes_detruire(ConteneurListe& cl);

/**
 * @brief Lecture d'un item d'un conteneur d'items.
 * @param[in] c Le conteneur d'items.
 * @param[in] i La position de l'item dans le conteneur.
 * @return L'item à la position i.
 * @pre i < c.capacite
 */
Liste clistes_lire(const ConteneurListe& cl, unsigned int i);

/**
 * @brief Ecrire un item dans un conteneur d'items.
 * @param[in,out] c Le conteneur d'items.
 * @param[in] i La position où ajouter/modifier l'item.
 * @param[in] it L'item à écrire.
 */
void clistes_ecrire(ConteneurListe& cl, unsigned int i, const Liste& l);

/**
 * @brief Rassemble tous les éléments de listes en une seule.
 * @param[in,out] c Le conteneur de listes.
 * @return Une liste contenant tous les items des listes du conteneur de listes.
 */
Liste clistes_join(const ConteneurListe& cl);