/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:37:04 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/14 16:20:19 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <iostream>

RPN::RPN() {}

RPN::RPN(const RPN& other) {
	*this = other;
}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other)
		stack = other.stack;
	return *this;
}

RPN::~RPN() {};

int RPN::evaluate(const std::string& expression) {
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (isdigit(token[0])) {
			stack.push(std::stod(token));
		} else if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (stack.size() < 2)
				throw std::runtime_error("Error: insufficient values in expression");
			int second = stack.top(); stack.pop();
			int first = stack.top(); stack.pop();
			if (token == "+") stack.push(first + second);
			else if (token == "-") stack.push(first - second);
			else if (token == "*") stack.push(first * second);
			else if (token == "/") {
				if (second == 0)
					throw std::runtime_error("Error: Division by 0");
				stack.push(first / second);
			}
		} else {
			throw std::runtime_error("Error: Invalid token!");
		}
	}
	if (stack.size() != 1) {
		throw std::runtime_error("Error: the expression does not evaluate to a single value.");
	}
	return (stack.top());
}