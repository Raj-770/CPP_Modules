/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:58:56 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/07 10:07:58 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	*this = src;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != other) {
		for (int i = 0; i < 100; i++){
			ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain deconstructor called" << std::endl;
}

std::string Brain::getIdea(int index) const {
	--index;
	if (index >=0 && index < 100)
		return ideas[index];
	return ("Invalid Index!");
}

void Brain::setIdea(int index, const std::string& idea) {
	--index;
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

void Brain::printIdeas(void) const {
	for (int i = 0; i < 100; i++) {
		if (ideas[i].empty() == false)
			std::cout << "Idea " << i + 1 << ": " << idea[i] << std::endl;
	}
}