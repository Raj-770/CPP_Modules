/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:46:46 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/01 15:54:55 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void) {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Memory Address of the string variable: " << &string << std::endl;
	std::cout << "Memory Address held by stringPTR     : " << stringPTR << std::endl;
	std::cout << "Memory Address held by stringREF     : " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "The value of the string variable : " << string << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
}