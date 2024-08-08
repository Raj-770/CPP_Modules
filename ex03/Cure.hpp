/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:41:08 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/07 17:43:14 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		virtual ~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);
}

#endif