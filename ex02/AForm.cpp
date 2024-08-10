/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:01:20 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/10 09:45:04 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException(_name + ", Grade too high!");
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException(_name + ", Grade too low!");
}

AForm::AForm(const Form& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return _name; }

bool AForm::getIsSigned() const { return _isSigned; }

int AForm::getGradeToSign() const { return _gradeToSign; }

int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (this->_gradeToSign < bureaucrat.getGrade())
		throw AForm::GradeTooLowException("bureaucrat Grade too Low");
	if (this->_isSigned == false)
		this->_isSigned = true;
}

void AForm::checkExecutionRequirements(const Bureaucrat& bureaucrat) const {
	if (this->_isSigned == false)
		throw AForm::FormNotSignedException("Form has not been signed!");
	if (this->_gradeToExecute < bureaucrat.getGrade())
		throw AForm::GradeTooLowException("Bureaucrate level to low to execute the Form");
}

std::ostream &operator<<(std::ostream &output, const AForm &form) {
	output << "\nForm Name: " << form.getName()
		<< ",\nIs the form Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ",\nGrade to Sign the form: " << form.getGradeToSign()
		<< ",\nGrade to Execute the Form: " << form.getGradeToExecute();

	return output;
}

AForm::GradeTooHighException::GradeTooHighException(const std::string &message) : std::runtime_error(message) {}

AForm::GradeTooLowException::GradeTooLowException(const std::string &message) : std::runtime_error(message) {}

AForm::FormNotSignedException::FormNotSignedException(const std::string &message) : std::runtime_error(message) {}
