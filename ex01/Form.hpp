/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:22:41 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/09 18:16:15 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		Form(const std::string &name, const int gradeToSign, const int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string& getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::runtime_error {
			public:
				GradeTooHighException(const std::string &message);
		};

		class GradeTooLowException : public std::runtime_error {
			public:
				GradeTooLowException(const std::string &message);
		};
};

std::ostream& operator<<(std::ostream &output, Form const &form);

#endif