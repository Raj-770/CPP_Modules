/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:29:25 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/03 17:31:59 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
	std::string name;

public:
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &source);
	DiamondTrap &operator=(const DiamondTrap &source);
	~DiamondTrap();

	void attack(const std::string &target);
	void whoAmI();
};

#endif