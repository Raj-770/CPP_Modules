/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:25:58 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/01 15:37:28 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int N = 5;
	std::string name = "HordeZombie";

	// Create a horde of zombies
	Zombie* horde = zombieHorde(N, name);

	// Announce each zombie
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}

	// Clean up the horde
	delete[] horde; // Use delete[] since it's an array allocation

	return 0;
}