/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:55:58 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/11 17:01:32 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* array, size_t length, void (*func)(T&)) {
	for (size_t i = 0; i < lenght; i++)
		func(array[i]);
}

template <typename T>
void printElemet(T element) {
	std::cout << element << " ";
}

template <typename T>
void increment(T element) {
	element++;
}

#endif