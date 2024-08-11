/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:40:12 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/11 14:54:42 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) { (void)other; }

Serializer& Serializer::operator=(const Serializer& other) { (void)other; return (*this); }

Serializer::~Serializer() {}

/*
reinterpret_cast is a type of casting operator in C++ that allows you to convert
one pointer type to another, one integral type to a pointer, or a pointer to an
integral type. This operator performs a low-level reinterpretation of the bit
pattern of its operand. It does not change the value during the conversion, but
rather it tells the compiler to treat the sequence of bits as if they were a
different type.
*/

uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}
