/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:38:00 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/08 14:52:29 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
	// Create Materia source
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Create characters
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	// Create and equip materia
	AMateria* ice = src->createMateria("ice");
	AMateria* cure = src->createMateria("cure");
	AMateria* secondIce = src->createMateria("ice");
	AMateria* thirdIce = src->createMateria("ice");
	AMateria* fourthIce = src->createMateria("ice");
	AMateria* overflowIce = src->createMateria("ice");

	me->equip(ice);
	me->equip(cure);
	me->equip(secondIce);
	me->equip(thirdIce);
	me->equip(fourthIce); // This should not equip because only 4 slots are available

	// Use materias
	std::cout << "Using equipped materias on Bob:" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	// Display what happens when trying to use an unequipped slot
	std::cout << "Attempting to use an overflow slot:" << std::endl;
	me->use(4, *bob); // Should not output anything

	// Testing unequip
	std::cout << "Testing unequip function:" << std::endl;
	me->unequip(1); // Cure should be unequipped
	me->use(1, *bob); // Should not output anything, slot is now empty

	// Test unequip non-existent slot
	std::cout << "Attempting to unequip non-existent slot:" << std::endl;
	me->unequip(5); // Should do nothing

	// Cleanup and showing what's left unequipped does not delete
	std::cout << "Equipping materia in previously unequipped slot:" << std::endl;
	me->equip(overflowIce);
	me->use(1, *bob); // Should now work with the overflowIce

	// Clean up
	delete bob;
	delete me;
	delete src;
	delete cure;

	std::cout << "All done. Resources cleaned up." << std::endl;

	return 0;
}
