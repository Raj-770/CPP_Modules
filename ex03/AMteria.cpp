/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMteria.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:14:33 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/07 17:29:13 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		_type = other._type
	}
	return (*this);
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
	return (_type);
}

void AMateria::use(ICharcter& target) {
	std::cout << "Using AMateria on " << target.getName() << std::endl;
}