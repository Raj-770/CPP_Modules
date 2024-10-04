/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:23:02 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/01 15:25:00 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* Stack Allocation (randomChump): Use when the Zombie's lifecycle
is limited to the function where it's created, typically for
temporary objects. */

void randomChump(std::string name) {
	Zombie zombie(name);
	zombie.announce();
}