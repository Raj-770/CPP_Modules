/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:20:12 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/12 12:26:43 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
	try {
		std::vector<int> vector;
		vector.push_back(1);
		vector.push_back(2);
		vector.push_back(3);
		vector.push_back(4);
		vector.push_back(5);
		std::vector<int>::iterator itr = easyfind(vector, 4);
		std::cout << "Found: " << *itr << std::endl;

		itr = easyfind(vector, 6);
		std::cout << "Found: " << *itr << std::endl;
	} catch (const NotFoundException &e) {
		std::cout << "Execption caught: " << e.what() << std::endl;
	}

	try {
		std::list<int> list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.push_back(4);
		list.push_back(5);
		std::list<int>::iterator itr = easyfind(list, 3);
		std::cout << "Found: " << *itr << std::endl;

		itr = easyfind(list, 6);
		std::cout << "Found: " << *itr << std::endl;
	} catch (const NotFoundException &e) {
		std::cout << "Execption caught: " << e.what() << std::endl;
	}
}