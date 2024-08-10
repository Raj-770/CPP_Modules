/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:10:19 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/10 12:57:01 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
		if (rrf)
			delete rrf;

		rrf = someRandomIntern.makeForm("Shrubbery Creation", "home");
		if (rrf)
			delete rrf;

		rrf = someRandomIntern.makeForm("Presidential Pardon", "Trillian");
		if (rrf)
			delete rrf;

		rrf = someRandomIntern.makeForm("unknown form", "unknown");
		if (rrf)
			delete rrf;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}