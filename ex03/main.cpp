/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:08:23 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/03 17:31:35 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	DiamondTrap dt("UltimateDiamond");

	dt.attack("the darkness itself");  // ScavTrap's attack
	dt.takeDamage(100);
	dt.beRepaired(50);
	dt.highFivesGuys();               // FragTrap's special ability
	dt.guardGate();                   // ScavTrap's special ability
	dt.whoAmI();                      // DiamondTrap's special ability

	return 0;
}