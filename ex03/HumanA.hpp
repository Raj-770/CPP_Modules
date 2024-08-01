/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:08:58 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/01 16:16:14 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA {
	private:
		Weapon &_weapon;
		std::string _name;

	public:
		HumanA(Weapon &weapon, std::string name);
		~HumanA();

		void attacks(void) const;
};

#endif