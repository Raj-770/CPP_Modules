/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:18:22 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/01 16:31:34 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		Weapon *_weapon;
		std::string _name;

	public:
		HumanB(std::string name);
		~HumanB();

		void attack(void) const;
		void setWeapon(Weapon &weapon);
};

#endif