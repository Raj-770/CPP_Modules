/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:24:33 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/02 17:27:24 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point {
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point();
		Point(float x, float y);
		Point(const Point& other);
		Point &operator=(const Point& other);
		~Point();

		Fixed getX() const;
		Fixed getY() const;
}

#endif