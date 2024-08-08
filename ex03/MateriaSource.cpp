/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:32:10 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/08 15:23:20 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; ++i)
		templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; ++i)
		templates[i] = other.templates[i] ? other.templates[i]->clone() : NULL;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; ++i) {
			delete templates[i];
			templates[i] = other.templates[i] ? other.templates[i]->clone() : NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) delete templates[i];
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; ++i) {
		if (!templates[i]) {
			templates[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; ++i) {
		if (templates[i] && templates[i]->getType() == type) {
			return templates[i]->clone();
		}
	}
	return NULL;
}
