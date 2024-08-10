/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:22:41 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/10 12:54:06 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		AForm(const std::string &name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string& getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat &bureaucrat);
		void checkExecutionRequirements(const Bureaucrat &bureaucrat) const;
		virtual void execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::runtime_error {
			public:
				GradeTooHighException(const std::string &message);
		};

		class GradeTooLowException : public std::runtime_error {
			public:
				GradeTooLowException(const std::string &message);
		};

		class FormNotSignedException : public std::runtime_error {
			public:
				FormNotSignedException(const std::string &message);
		};
};

std::ostream& operator<<(std::ostream &output, AForm const &form);

#endif