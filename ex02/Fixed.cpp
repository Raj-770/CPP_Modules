/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:11:17 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/02 17:04:59 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

// Default constructor
Fixed::Fixed() : _value(0) {}

// Integer constructor
Fixed::Fixed(const int intVal) : _value(intVal << _fractionalBits) {}

// Float constructor
Fixed::Fixed(const float floatVal) : _value(roundf(floatVal * (1 << _fractionalBits))) {}

// Copy constructor
Fixed::Fixed(const Fixed &other) : _value(other._value) {
	*this = other;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		this->_value = other.getRawBits();
	}
	return (*this);
}

// Destructor
Fixed::~Fixed() {
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
bool Fixed::operator>(const Fixed &other) const {
	return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const {
	return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const {
	return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const {
	return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const {
	return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const {
	return (this->_value != other._value);
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_value + other._value);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_value - other._value);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result.setRawBits((this->_value * other._value) >> _fractionalBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	result.setRawBits((this->_value << _fractionalBits) / other._value);
	return (result);
}

// Increment and decrement operators
Fixed& Fixed::operator++() {
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++(*this);
	return (temp);
}

Fixed& Fixed::operator--() {
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--(*this);
	return (temp);
}


// Min and Max functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b ? a : b);
}
