/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:03:44 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/12 15:18:35 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <limits>
#include <iostream>

class Span {
	private:
		std::vector<int> numbers;
		unsigned int max_size;

	public:
		Span(unsigned int max_size);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		void addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);
		int shortestSpan() const;
		int longestSpan()const;
};

#endif