/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:08:23 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/03 15:23:29 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
	// Test ClapTrap
	ClapTrap ct("CT-01");
	ct.attack("Enemy");
	ct.takeDamage(5);
	ct.beRepaired(3);
	ct.takeDamage(6);
	ct.attack("Enemy");
	ct.beRepaired(4);

	// Test ScavTrap
	ScavTrap st("ST-01");
	st.attack("Enemy");
	st.takeDamage(30);
	st.beRepaired(10);
	st.guardGate();
	st.takeDamage(100);
	st.attack("Enemy");
	st.beRepaired(50);

	return 0;
}
