/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:35:47 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/12 15:22:14 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int max_size) : max_size(max_size) {}

Span::Span(const Span& other) : numbers(other.numbers), max_size(other.max_size) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		numbers = other.numbers;
		max_size = other.max_size;
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (numbers.size() >= max_size) {
		throw std::length_error("Span has reached its maximum capacity");
	}
	numbers.push_back(number);
}

void Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	while (start != end) {
		addNumber(*start);
		start++;
	}
}

int Span::shortestSpan() const {
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough elements to find a span");
	std::vector<int> sorted(numbers);
	std::sort(sorted.begin(), sorted.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 0; i < sorted.size() - 1; ++i) {
		int span = sorted[i + 1] - sorted[i];
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

int Span::longestSpan() const {
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough elements to find a span");
	std::vector<int> sorted(numbers);
	std::sort(sorted.begin(), sorted.end());
	return (sorted[sorted.size() -  1] - sorted[0]);
}
