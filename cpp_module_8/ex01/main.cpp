/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:17:51 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/12 15:24:10 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int main() {
	Span sp(10000);
	srand(time(NULL));  // Seed random number generator

	// Add random numbers to Span
	try {
		for (int i = 0; i < 10000; i++) {
			// sp.addNumber(rand() % 100000);
			sp.addNumber(i);
		}
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
