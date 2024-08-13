/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:44:43 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/13 14:25:21 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>

class BitcoinExchange {
	private:
		std::map<std::string, double> exchangeRate;
		bool isValidDate(const std::string& date);
		std::pair<std::string, double> parseData(const std::string& data_line, char delimeter);
		std::map<std::string, double> readDatabase(const std::string& db_file);

	public:
		BitcoinExchange(std::string& fileName);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		double getExchangeRate(const std::string& data_line);
		std::pair<std::string, double> getExchnageVlaue(const std::string& data_line);
};

#endif