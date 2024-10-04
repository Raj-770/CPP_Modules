/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:43:34 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/14 13:01:26 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./btc <filename>" << std::endl;
		return (1);
	}
	std::ifstream file(argv[1]);
	if (!file) {
		std::cerr << "Error: could not open file" << std::endl;
		return (1);
	}

	try {
		BitcoinExchange exchange("data.csv");
		std::string line;

		std::getline(file, line);
		if (line != "date | value")
			std::cout << "Error: Format Error: The file should have \"date | value\" as header" << std::endl;
		while (std::getline(file, line)) {
			try {
				std::pair<double, double> value = exchange.getExchangeValue(line);
				std::cout << line.substr(0, line.find('|')) << "=> " << value.first << " = " << (value.first * value.second) << std::endl;
			} catch (const std::exception& e){
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
	} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			file.close();
			return (-1);
		}
	file.close();
	return (0);
}
