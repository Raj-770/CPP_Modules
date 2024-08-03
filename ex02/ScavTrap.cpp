/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:17:52 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/03 16:03:30 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &source) : ClapTrap(source) {
	std::cout << "ScavTrap " << this->name << " copied." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &source) {
	ClapTrap::operator=(source);
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " destroyed." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	} else {
		std::cout << "ScavTrap " << this->name << " cannot attack due to low energy or hit points!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}