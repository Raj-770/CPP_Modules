/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:08:23 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/03 16:14:24 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("ClapUnit");
    ScavTrap scav("ScavUnit");
    FragTrap frag("FragUnit");

    clap.attack("a target");
    scav.attack("a different target");
    frag.attack("yet another target");

    clap.takeDamage(10);
    scav.takeDamage(20);
    frag.takeDamage(30);

    clap.beRepaired(5);
    scav.beRepaired(10);
    frag.beRepaired(15);

    scav.guardGate();
    frag.highFivesGuys();

    return 0;
}