/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:30:00 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/10 12:56:09 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern {
	private:
		AForm* makeShrubberyCreationForm(const std::string &target);
		AForm* makeRobotomyRequestForm(const std::string &target);
		AForm* makePresidentialPardonForm(const std::string &target);

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		class FormNotFoundException : public std::runtime_error {
			public:
				FormNotFoundException(const std::string& message);
		};

		AForm* makeForm(const std::string &name, const std::string &target);
};

typedef AForm* (Intern::*FormCreationFunction)(const std::string& target);

struct Forms {
		std::string formName;
		FormCreationFunction makerFunction;
};

#endif