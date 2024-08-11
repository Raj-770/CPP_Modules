/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:43:27 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/11 13:27:02 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>

struct ScalarData {
	char charValue;
	long integerValue;
	double floatValue;
	double doubleValue;
};

enum Type { CHAR, INT, FLOAT, DOUBLE, PSEUDO, UNKNOWN };

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		Type findType(std::string& literal, ScalarData& scalarData);
		void formatPseudoLiterals(const std::string& literal);
		void formatCharAsScalars(char charValue);
		void formatIntAsScalars(long intValue);
		void formatFloatAsScalars(double floatValue);
		void formatDoubleAsScalars(long double doubleVlaue);

	public:
		static void convert(const std::string &input);
};

#endif