/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:19:03 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/01 15:25:02 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* Heap Allocation (newZombie): Use when the
Zombie needsto persist beyond the function
scope where it was created.*/

Zombie *newZombie(std::string name) {
	return (new Zombie(name));
}