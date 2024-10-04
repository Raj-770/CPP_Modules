/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:59:18 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/12 17:04:13 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
	MutantStack<int> ms;
	std::list<int> lst;

	std::cout << "Testing MutantStack:" << std::endl;
	for (int i = 0; i < 5; i++) {
		ms.push(i + 1);
	}

	MutantStack<int>::iterator it1 = ms.begin();
	MutantStack<int>::iterator ite1 = ms.end();
	std::cout << "Container contents: ";
	while (it1 != ite1) {
		std::cout << *it1 << ' ';
		++it1;
	}
	std::cout << std::endl;

	std::cout << "Testing std::list:" << std::endl;
	for (int i = 0; i < 5; i++) {
		lst.push_back(i + 1);
	}

	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	std::cout << "Container contents: ";
	while (it != ite) {
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;

	return 0;
}
