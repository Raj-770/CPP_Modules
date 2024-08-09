/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:31:48 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/09 16:40:37 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string const getName() const;
		int getGrade() const;

		void incrementGrade(int gradeToIncrease);
		void decrementGrade(int gradeToDecrease);

};

std::ostream& operator<<(std::ostream &output, Bureaucrat const& bureaucrat);

/* In the prototype the const throw() says the compiler that the function what won't thow any exceptions */
class GradeTooHighException : public std::runtime_error {
	public:
		GradeTooHighException(const std::string &message);
};

class GradeTooLowException : public std::runtime_error {
	public:
		GradeTooLowException(const std::string &message);
};

#endif