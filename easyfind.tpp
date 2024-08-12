/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:16:16 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/12 12:32:18 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

/*
The find algorithm is part of the <algorithm> header and provides a way to search
for an element in a container. It works with any container that provides forward
iterators. This function returns an iterator to the first element in the range
that compares equal to the value. If no such element is found, the function
returns an iterator to the end of the range provided to it.
*/

/*
An iterator in C++ is an object that enables a programmer to traverse a container,
particularly lists and arrays in a similar way that pointers can access the
elements of an array. Iterators abstract the container so that algorithms
can be written independently of the type of data structure.
*/

template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator itr = std::find(container.begin(), container.end(), value);
	if (itr == container.end())
		throw NotFoundException();
	return (itr);
}

#endif