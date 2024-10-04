/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:30:06 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/03 17:33:30 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

// Constructor that initializes base classes explicitly
DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), // Initialize ClapTrap explicitly with a modified name
	  FragTrap(name), ScavTrap(name), name(name) {
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << this->name << " constructed." << std::endl;
}

// Copy constructor must also explicitly initialize ClapTrap
DiamondTrap::DiamondTrap(const DiamondTrap &source)
	: ClapTrap(source.ClapTrap::name), // Explicitly initialize ClapTrap
	  FragTrap(source), ScavTrap(source),
	  name(source.name) {
	std::cout << "DiamondTrap copied from " << source.name << "." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &source) {
	if (this != &source) {
		ClapTrap::operator=(source); // Ensure ClapTrap parts are assigned correctly
		FragTrap::operator=(source); // FragTrap assignment
		ScavTrap::operator=(source); // ScavTrap assignment
		this->name = source.name;    // DiamondTrap specific
	}
	std::cout << "DiamondTrap " << this->name << " assigned." << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " destroyed." << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target); // Use ScavTrap's attack method since it's specified
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
