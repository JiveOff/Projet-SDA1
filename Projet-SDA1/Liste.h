#pragma once

/**
 * @file Liste.h
 * @brief Composant de liste en mémoire dynamique et extensible.
 */

#include "ConteneurTDE.h"

 /**
  * @brief Structure Liste.
  */
struct Liste {
	/// Conteneur mémorisant les éléments de la liste.
	ConteneurTDE c;
	/// Nombre d'éléments stockés dans la liste.
	unsigned int nb;
};

/**
 * @brief Initialiser une liste vide, la liste est allouée en mémoire dynamique.
 * @see detruire, la liste est à désallouer en fin d’utilisation.
 * @param[out] l La liste à initialiser.
 * @param[in] capa Capacité de la liste.
 * @param[in] pas Pas d’extension de la liste.
 * @pre capa > 0 et pas > 0.
 */
void initialiser(Liste& l, unsigned int capa, unsigned int pas);

/**
 * @brief Désallouer une liste.
 * @see initialiser
 * @param[out] l La liste.
 */
void detruire(Liste& l);

/**
 * @brief Longueur de liste.
 * @param[in] l La liste.
 * @return La longueur de la liste.
 */
unsigned int longueur(const Liste& l);

/**
 * @brief Lire un élément de liste.
 * @param[in] l La liste.
 * @param[in] pos Position de l'élément à lire.
 * @return L'item lu en position pos.
 * @pre 0 <= pos < longueur(l).
 */
Item lire(const Liste& l, unsigned int pos);

/**
 * @brief Ecrire un item dans la liste.
 * @param[in,out] l La liste.
 * @param[in] pos Position de l'élément à écrire.
 * @param[in] it L'item.
 * @pre 0 <= pos < longueur(l).
*/
void ecrire(Liste& l, unsigned int pos, const Item& it);

/**
 * @brief Insérer un élément dans une liste.
 * @param[in,out] l La liste.
 * @param[in] pos La position à laquelle l'élément est inséré.
 * @param[in] it L'élément inséré.
 * @pre 0 <= pos <= longueur(l).
 */
void inserer(Liste& l, unsigned int pos, const Item& it);

/**
 * @brief Supprimer un élément dans une liste.
 * @param[in,out] l La liste.
 * @param[in] pos La position de l'élément à supprimer.
 * @pre longueur(l) > 0 et 0 <= pos < longueur(l).
 */
void supprimer(Liste& l, unsigned int pos);

/**
 * @brief Ordonner la liste alphabétiquement.
 * @param[in,out] l La liste.
 */
void ordonner(Liste& l);

/**
 * @brief Insérer les mots jusqu'à la fin d'une liste (mentionnée par une *).
 * @param[in,out] l La liste.
 * @pre longueur(l) > 0.
 */
void entreeEtoile(Liste& l);

/**
 * @brief Affiche le mot à la position pos de la liste.
 * @param[in] l La liste.
 * @param[in] pos La position de l'élément.
 */
void afficher(const Liste& l, unsigned int pos);

/**
 * @brief Affiche une liste et mentionne sa fin avec une "*".
 * @param[in] l La liste.
 */
void afficherListe(const Liste& l);

/**
 * @brief Compare deux listes et retourne une liste en fonction du filtre.
 * @param[in,out] l_1 La liste.
 * @param[in,out] l_2 La liste.
 * @param[in] filtre Fonction permettant de filtrer.
 * @return Une liste ayant appliqué le filtre donné.
 */
Liste filtrer(Liste& l_1, Liste& l_2, bool (*filtre)(Liste& l, Item& it));

/**
 * @brief Récupérer l'indice d'un item donné dans une liste l.
 * @param[in] l La liste.
 * @param[in] it L'item à retrouver.
 * @return L'index de l'item it dans la liste l.
 * @pre l.nb > 0
 */
unsigned int getByItem(const Liste& l, const Item& it);

/**
 * @brief Transforme une liste donnée en liste canonique, c'est-à-dire:
 *	les mots sont triés par ordre alphabétique croissant
 *	chaque mot n'apparaît d'une unique fois
 * @param[in] l La liste.
 * @return La liste transformée.
 * @pre l.nb > 0
 */
Liste formeCanonique(Liste& l);

/**
 * @brief Compte le nombre de fois qu'un élément apparait dans la liste.
 * @param[in] l La liste.
 * @param[in] it L'item permettant la comparaison.
 * @return Le nombre d'occurences de l'item it dans la liste l.
 * @pre 0 <= pos <= longueur(l).
 */
unsigned int occurences(const Liste& l, const Item& it);