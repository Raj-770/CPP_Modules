/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:08:26 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/03 14:28:57 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include<string>
# include<iostream>

class ClapTrap {
	private:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& source);
		ClapTrap &operator=(const ClapTrap& source);
		~ClapTrap();

		void attack(const std::string& traget);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif