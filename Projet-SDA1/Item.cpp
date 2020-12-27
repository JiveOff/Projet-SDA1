/**
 * @file Item.cpp
 * @brief Utilitaires de manipulation des items.
 */

#include <iostream>
#include "Item.h"

Item saisie() {
	Item it;
	std::cin >> it.mot;
	return it;
}