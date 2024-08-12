/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:46:44 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/12 14:21:36 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return (*this); };

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
	ScalarConverter converter;
	std::string literalCopy = literal;
	ScalarData scalarData;

	Type type = converter.findType(literalCopy, scalarData);
	switch (type) {
		case PSEUDO:
			converter.formatPseudoLiterals(literal);
			break;
		case CHAR:
			converter.formatCharAsScalars(scalarData.charValue);
			break;
		case INT:
			converter.formatIntAsScalars(scalarData.integerValue);
			break;
		case FLOAT:
			converter.formatFloatAsScalars(scalarData.floatValue);
			break;
		case DOUBLE:
			converter.formatDoubleAsScalars(scalarData.doubleValue);
			break;
		default:
			std::cout << "Invalid input!" << std::endl;
			break;
	}
}

bool containsTwoOrMoreDots(const std::string& input) {
	int dotCount = 0;
	for (unsigned int i = 0; i < input.length(); i++) {
		if (input[i] == '.') {
			dotCount++;
			if (dotCount >= 2) {
				return true;
			}
		}
	}
	return false;
}

/**
 * @brief finds the type of the literal with the help if input string stream.
 *
 * @param literal
 * @return std::string
 */
Type ScalarConverter::findType(std::string& literal, ScalarData& scalarData) {
	std::istringstream input(literal);

	if (containsTwoOrMoreDots(literal))
		return (UNKNOWN);

	// Checking if it is a psuedo literal
	if (literal == "nan" || literal == "-inf" || literal == "+inf" || literal == "inf" || literal == "nanf" || literal == "-inff" || literal == "+inff" || literal == "inff")
		return (PSEUDO);

	// Checking if it is a character
	if (literal.length() == 1 && std::isprint(literal[0]) && std::isdigit(literal[0]) == false) {
		scalarData.charValue = literal[0];
		return (CHAR);
	}

	// Checking if it is a integer
	input.clear();
	input.str(literal);
	input >> scalarData.integerValue;
	if (!input.fail() && input.eof())
		return (INT);

	// Checking if it is a float
	input.clear();
	std::string::reverse_iterator reverseIterator = literal.rbegin();
	if (*reverseIterator == 'f' || *reverseIterator == 'F')
		literal = literal.substr(0, literal.length() -  1);
	input.str(literal);
	input >> scalarData.floatValue;
	if (!input.fail() && input.eof())
		return (FLOAT);

	// Checking if it is a double
	input >> scalarData.doubleValue;
	if (!input.fail() && input.eof())
		return (DOUBLE);

	// If no match found return UNKOWN
	return (UNKNOWN);
}

void ScalarConverter::formatPseudoLiterals(const std::string& literal) {
	std::cout << "char: Conversion not possible!" << std::endl;
	std::cout << "int: Conversion not possible!" << std::endl;

	if (literal == "nan" || literal == "-inf" || literal == "+inf" || literal == "inf") {
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
	}

	if (literal == "nanf" || literal == "-inff" || literal == "+inff" || literal == "inff")	{
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
	}
}

void ScalarConverter::formatCharAsScalars(char charValue) {
	std::cout	<< "char: " << charValue << std::endl
				<< "int: " << static_cast<int>(charValue) << std::endl
				<< std::fixed
				<< "float: " << static_cast<float>(charValue) << "f" << std::endl
				<< "double: " << static_cast<double>(charValue) << std::endl;
}

void ScalarConverter::formatIntAsScalars(long intValue) {
	if (intValue < std::numeric_limits<char>::min() || intValue > std::numeric_limits<char>::max())
		std::cout << "char: Overflow" << std::endl;
	else if (!std::isprint(static_cast<char>(intValue)))
		std::cout << "char: Not printable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(intValue) << std::endl;

	if (intValue < std::numeric_limits<int>::min() || intValue > std::numeric_limits<int>::max())
		std::cout << "int: Overflow" << std::endl;
	else
		std::cout << "int: " << intValue << std::endl;

	std::cout	<< std::fixed << std::setprecision(1)
				<< "float: " << static_cast<float>(intValue) << "f" << std::endl
				<< "double: " << static_cast<double>(intValue) << std::endl;
}

void ScalarConverter::formatFloatAsScalars(double floatValue) {
	if (floatValue < std::numeric_limits<char>::min() || floatValue > std::numeric_limits<char>::max())
		std::cout << "char: Overflow" << std::endl;
	else if (!std::isprint(static_cast<char>(floatValue)))
		std::cout << "char: Not printable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(floatValue) << std::endl;

	if (floatValue < std::numeric_limits<int>::min() || floatValue > std::numeric_limits<int>::max())
		std::cout << "int: Overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(floatValue) << std::endl;

	std::cout << std::fixed;

	if (floatValue > std::numeric_limits<float>::max() || floatValue < std::numeric_limits<float>::lowest()) {
		std::cout << "float: Overflow" << std::endl;
	}
	else
		std::cout << "float: " << static_cast<float>(floatValue) << "f" << std::endl;
	std::cout << "double: " << floatValue << std::endl;
}

void ScalarConverter::formatDoubleAsScalars(long double doubleValue) {
	if (doubleValue < std::numeric_limits<char>::min() || doubleValue < std::numeric_limits<char>::max())
		std::cout << "char: Overflow" << std::endl;
	else if (!std::isprint(static_cast<char>(doubleValue)))
		std::cout << "char: Not printable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(doubleValue) << std::endl;

	if (doubleValue < std::numeric_limits<int>::min() || doubleValue > std::numeric_limits<int>::max())
		std::cout << "int: Overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;

	std::cout << std::fixed;

	if (doubleValue > std::numeric_limits<float>::max() || doubleValue < std::numeric_limits<float>::lowest()) {
		std::cout << "float: Overflow" << std::endl;
	}
	else
		std::cout << "float: " << static_cast<float>(doubleValue) << "f" << std::endl;
	if (doubleValue > std::numeric_limits<double>::max() || doubleValue < std::numeric_limits<double>::lowest()) {
		std::cout << "double: Overflow" << std::endl;
	}
	else
		std::cout << "double: " << static_cast<float>(doubleValue) << std::endl;
}