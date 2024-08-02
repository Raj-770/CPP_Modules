/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:11:17 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/02 16:05:07 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

// Default constructor
Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Integer constructor
Fixed::Fixed(const int intVal) : _value(intVal << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

// Float constructor
Fixed::Fixed(const float floatVal) : _value(roundf(floatVal * (1 << _fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : _value(other._value) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_value = other.getRawBits();
	}
	return (*this);
}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Get the raw fixed-point value
int Fixed::getRawBits(void) const {
	return (this->_value);
}

// Set the raw fixed-point value
void Fixed::setRawBits(const int raw) {
	this->_value = raw;
}

// Convert to int
int Fixed::toInt(void) const {
	return (_value >> _fractionalBits);
}

// Convert to float
float Fixed::toFloat(void) const {
	return ((static_cast<float>(_value)) / (1 << _fractionalBits));
}

// Overload << operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) {
	return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed &other) {
	return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) {
	return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) {
	return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) {
	return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) {
	return (this->_value != other._value);
}