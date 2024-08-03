/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:08:19 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/03 14:54:48 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &source) : name(source.name), hitPoints(source.hitPoints), energyPoints(source.energyPoints), attackDamage(source.attackDamage) {}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;

	return (*this);
}

// Destructor
ClapTrap::~ClapTrap() {}

// Member functions
void ClapTrap::attack(const std::string &target) {
	if (hitPoints > 0 && energyPoints > 0) {
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "ClapTrap " << name << " cannot take more damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints > 0) {
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
		hitPoints = amount > hitPoints ? 0 : hitPoints - amount;
	} else {
		std::cout << "ClapTrap " << name << " cannot take more damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints > 0 && hitPoints > 0) {
		std::cout << "ClapTrap " << name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
		hitPoints += amount;
		energyPoints--;
	} else {
		std::cout << "ClapTrap " << name << " cannot repair due to low energy or hit points!" << std::endl;
	}
}
