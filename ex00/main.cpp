/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:08:23 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/03 14:55:47 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap ct("CT-01");
	ct.attack("Enemy");
	ct.takeDamage(5);
	ct.beRepaired(3);
	ct.takeDamage(6);
	ct.attack("Enemy");
	ct.beRepaired(4);

	return 0;
}
