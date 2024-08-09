/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:01:20 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/09 18:19:52 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, const int gradeToSign, const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException(_name + ", Grade too high!");
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException(_name + ", Grade too low!");
}

Form::Form(const Form& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form() {}

const std::string &Form::getName() const { return _name; }

bool Form::getIsSigned() const { return _isSigned; }

int Form::getGradeToSign() const { return _gradeToSign; }

int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (this->_gradeToSign < bureaucrat.getGrade())
		throw Form::GradeTooLowException("bureaucrat Grade too Low");
	if (this->_isSigned == false)
		this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &output, const Form &form) {
	output << "\nForm Name: " << form.getName()
		<< ",\nIs the form Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ",\nGrade to Sign the form: " << form.getGradeToSign()
		<< ",\nGrade to Execute the Form: " << form.getGradeToExecute();

	return output;
}

Form::GradeTooHighException::GradeTooHighException(const std::string &message) : std::runtime_error(message) {}

Form::GradeTooLowException::GradeTooLowException(const std::string &message) : std::runtime_error(message) {}
