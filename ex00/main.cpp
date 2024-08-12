/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:42:21 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/12 11:55:34 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
		return 0;
	}
	// std::cout << "Testing with a normal integer:" << std::endl;
	// ScalarConverter::convert("42");
	// std::cout << std::endl << std::endl;

	// std::cout << "Testing with a negative integer:" << std::endl;
	// ScalarConverter::convert("-42");
	// std::cout << std::endl << std::endl;

	// // Test with a character
	// std::cout << "Testing with a character:" << std::endl;
	// ScalarConverter::convert("a");
	// std::cout << std::endl << std::endl;


	// // Test with a floating-point number
	// std::cout << "Testing with a float:" << std::endl;
	// ScalarConverter::convert("3.14f");
	// std::cout << std::endl << std::endl;

	// // Test with a double precision floating-point number
	// std::cout << "Testing with a double:" << std::endl;
	// ScalarConverter::convert("3.14159");
	// std::cout << std::endl << std::endl;

	// // Test with a large double (scientific notation)
	// std::cout << "Testing with a large double:" << std::endl;
	// ScalarConverter::convert("1e40");
	// std::cout << std::endl << std::endl;

	// // Test with a small double (scientific notation)
	// std::cout << "Testing with a small double:" << std::endl;
	// ScalarConverter::convert("1e-40");
	// std::cout << std::endl << std::endl;

	// // Test with special float pseudo literals
	// std::cout << "Testing with positive infinity (float):" << std::endl;
	// ScalarConverter::convert("inff");
	// std::cout << std::endl << std::endl;

	// std::cout << "Testing with negative infinity (float):" << std::endl;
	// ScalarConverter::convert("-inff");
	// std::cout << std::endl << std::endl;


	// std::cout << "Testing with NaN (float):" << std::endl;
	// ScalarConverter::convert("nanf");
	// std::cout << std::endl << std::endl;


	// // Test with special double pseudo literals
	// std::cout << "Testing with positive infinity (double):" << std::endl;
	// ScalarConverter::convert("inf");
	// std::cout << std::endl << std::endl;

	// std::cout << "Testing with negative infinity (double):" << std::endl;
	// ScalarConverter::convert("-inf");
	// std::cout << std::endl << std::endl;

	// std::cout << "Testing with NaN (double):" << std::endl;
	// ScalarConverter::convert("nan");
	// std::cout << std::endl << std::endl;

	return 0;
}
