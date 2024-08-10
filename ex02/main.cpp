/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:10:19 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/10 11:29:48 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat jeff("Jeff", 5);
		Bureaucrat bob("Bob", 5);

		ShrubberyCreationForm shrubbery("home");
		RobotomyRequestForm rob("asdas");
		PresidentialPardonForm par("pp");
		jeff.signForm(shrubbery);
		jeff.executeForm(shrubbery);
		jeff.signForm(rob);
		jeff.executeForm(rob);
		bob.signForm(par);
		bob.executeForm(par);


	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}