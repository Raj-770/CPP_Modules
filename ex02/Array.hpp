/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:26:04 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/11 17:31:24 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
	private:
		T* _array;
		unsigned int _size;

	public:
		Array();
		Array(const Array& other);
		operator=(const Array& other);
		~Array();

		T& operator[](unsigned int index);
		unsigned int size() const;
}

#include "Array.tpp"

#endif