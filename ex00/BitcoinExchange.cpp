/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:26:00 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/14 12:57:34 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& fileName) {
	this->exchangeRate = readDatabase(fileName);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) {
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy) {
	exchangeRate = copy.exchangeRate;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string& date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		return (false);
	}

	int year, month, day;
	try {
		year = std::stoi(date.substr(0, 4));
		month = std::stoi(date.substr(5, 2));
		day = std::stoi(date.substr(8, 2));
	} catch (const std::exception&) {
		return (false);
	}

	if (year < 1)
		return (false);

	const int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month < 1 || month > 12)
		return (false);

	if (day < 1 || day > month_days[month - 1])
		return (false);

	return (true);
}

std::pair<std::string, double> BitcoinExchange::parseData(const std::string& data_line, char delimiter) {
	size_t del_pos = data_line.find(delimiter);
	if (del_pos == std::string::npos) {
		throw std::runtime_error("Format error: missing delimiter");
	}
	std::string date = data_line.substr(0, 10);
	if (!isValidDate(date)) {
		throw std::invalid_argument("Invalid date: " + date);
	}
	std::string value_str = data_line.substr(del_pos + 1);
	double value = std::stod(value_str);
	if (value < 0) {
		throw std::domain_error("Negative number not allowed");
	}
	return {date, value};
}

std::map<std::string, double> BitcoinExchange::readDatabase(const std::string& database_file) {
	std::ifstream file(database_file);
	if (!file) {
		throw std::runtime_error("Could not open file: " + database_file);
	}
	std::map<std::string, double> db_content;
	std::string line;
	while (std::getline(file, line)) {
		try {
			std::pair<std::string, double> value = parseData(line, ',');
			db_content[value.first] = value.second;
		} catch (const std::exception& ) {

		}
	}
	return db_content;
}

double BitcoinExchange::getExchangeRate(const std::string& data_line) {
	std::pair<std::string, double> value = parseData(data_line, '|');
	std::map<std::string, double>::iterator it = exchangeRate.lower_bound(value.first);
	if (it != exchangeRate.begin() && it == exchangeRate.end())
		--it;
	if (it == exchangeRate.end())
		throw std::runtime_error("No applicable exchnage rate found");
	return it->second;
}

std::pair<double, double> BitcoinExchange::getExchangeValue(const std::string& data_line) {
	double rate = getExchangeRate(data_line);
	std::pair<std::string, double> value = parseData(data_line, '|');
	if (value.second > 2147483647)
		throw std::overflow_error("Value exceeds maximum allowed");
	return {value.second, rate};
}