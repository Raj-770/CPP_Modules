/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:36:48 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/10 12:55:58 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeShrubberyCreationForm(const std::string& target) {
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyRequestForm(const std::string& target) {
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidentialPardonForm(const std::string& target) {
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
	Forms forms[] = {
		{"Shrubbery Creation", &Intern::makeShrubberyCreationForm},
		{"Robotomy Request", &Intern::makeRobotomyRequestForm},
		{"Presidential Pardon", &Intern::makePresidentialPardonForm}
	};

	AForm *form = NULL;

	for (int i = 0; i < 3; i++) {
		if (forms[i].formName == name) {
			form = (this->*(forms[i].makerFunction))(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	throw Intern::FormNotFoundException("404 Form not found!");
}

Intern::FormNotFoundException::FormNotFoundException(const std::string &message) : std::runtime_error(message) {}
