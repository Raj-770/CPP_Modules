/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:10:19 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/09 16:43:07 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;

		bob.incrementGrade(1);
		std::cout << bob << std::endl;

		// bob.incrementGrade(1);
		// bob.decrementGrade(149);
		bob.decrementGrade(1);
		bob.decrementGrade(1);
		std::cout << bob << std::endl;
	} catch (const GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
