/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:13:36 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/01 16:32:57 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA (std::string name, Weapon &weapon): _weapon(weapon), _name(name) {}

HumanA::~HumanA () {}

void HumanA::attack(void) const {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
	return ;
}
