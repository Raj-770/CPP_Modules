/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:05:49 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/17 14:09:24 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error: No numbers provided." << std::endl;
		return (1);
	}
	PmergeMe sorter;
	sorter.parseInput(argc, argv);
	sorter.sortAndDisplayResults();

	return (0);
}