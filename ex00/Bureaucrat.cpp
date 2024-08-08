/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:54:18 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/08 20:09:08 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	if (grade < 1) throw GradeTooHighException();
	if (grade > 150) throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.name), _grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	// Can't assign constant name here
	if (this != &other) {
		this->grade = other.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

std::ostream& operator<<(std::ostream &output, Bureaucrat const& bureaucrat) {
	output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (output);
}

void Bureaucrat::incrementGrade(int gradeToIncrement) {
	if (_grade - gradeToIncrement < 1) throw GradeTooHighException();
	_grade -= gradeToIncrement;
}

void Bureaucrat::decrementGrade(int gradeToDecrement) {
	if (_grade + gradeToDecrement > 150) throw GradeTooLowException();
	_grade += gradeToDecrement;
}

