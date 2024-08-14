/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:44:43 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/13 17:42:50 by rpambhar         ###   ########.fr       */
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
		std::pair<std::string, double> parseData(const std::string& data_line, char delimiter);
		std::map<std::string, double> readDatabase(const std::string& db_file);

	public:
		BitcoinExchange(const std::string& fileName);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		double getExchangeRate(const std::string& data_line);
		std::pair<double, double> getExchangeValue(const std::string& data_line);
};

#endif