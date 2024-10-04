/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:54:18 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/10 11:47:55 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	if (grade < 1) throw Bureaucrat::GradeTooHighException(_name + " ,Grade too high!");
	if (grade > 150) throw Bureaucrat::GradeTooLowException(_name + " ,Grade too low!");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	// Can't assign constant name here
	if (this != &other) {
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string const Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::signForm(AForm& form)
{
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "." <<std::endl;
	} catch (std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName() << "." << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}


void Bureaucrat::incrementGrade(int gradeToIncrement) {
	if (_grade - gradeToIncrement < 1) throw Bureaucrat::GradeTooHighException(_name + " ,Grade too high!");
	_grade -= gradeToIncrement;
}

void Bureaucrat::decrementGrade(int gradeToDecrement) {
	if (_grade + gradeToDecrement > 150) throw Bureaucrat::GradeTooLowException(_name + " ,Grade too low!");
	_grade += gradeToDecrement;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &message) : std::runtime_error(message) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &message) : std::runtime_error(message) {}

std::ostream& operator<<(std::ostream &output, Bureaucrat const& bureaucrat) {
	output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (output);
}