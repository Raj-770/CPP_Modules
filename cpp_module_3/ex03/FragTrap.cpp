/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:13:53 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/03 16:14:05 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &source) : ClapTrap(source) {
	std::cout << "FragTrap " << this->name << " copied." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &source) {
	if (this != &source) {
		ClapTrap::operator=(source);
	}
	std::cout << "FragTrap " << this->name << " assigned." << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " destroyed." << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		std::cout << "FragTrap " << this->name << " attacks " << target
				  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	} else {
		std::cout << "FragTrap " << this->name << " cannot attack due to low energy or hit points!" << std::endl;
	}
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->name << " requests high fives!" << std::endl;
}