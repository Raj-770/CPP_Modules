/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:13:36 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/01 16:17:19 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA (Weapon &weapon, std::string name): _weapon(weapon), _name(name) {}

HumanA::~HumanA () {}

void HumanA::attacks(void) const {
	std::cout << _name >> " attacks with their" << _weapon->getType() << std::endl;
	return ;
}
