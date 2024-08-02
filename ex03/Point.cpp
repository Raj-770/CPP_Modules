/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:28:10 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/02 17:34:05 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor
Point::Point() : x(0), y(0) {}

// Constructor with floating point parameters
Point::Point(float xVal, float yVal) : x(xVal), y(yVal) {}

// Copy constructor
Point::Point(const Point& other) : x(other.x), y(other.y) {}

// Copy assignment operator (does nothing as x and y are const)
Point& Point::operator=(const Point& other) {
	return *this;
}

// Destructor
Point::~Point() {}

// getters
Fixed Point::getX() const {
	return (x);
}

Fixed Point::getY() const {
	return (y);
}
