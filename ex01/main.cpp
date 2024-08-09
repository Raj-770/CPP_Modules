/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:10:19 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/09 18:18:17 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
	try {

		// Create forms with various grades
		Form highForm("High Form", 50, 50);
		Form lowForm("Low Form", 150, 150);
		Form invalidHighForm("Invalid High Form", 0, 100);  // This should throw an exception
	} catch (const std::exception& e) {
		std::cerr << "Exception caught during form creation: " << e.what() << std::endl;
	}

	try {
		Bureaucrat middleBureaucrat("Middle Manager", 75);
		// Create a valid form
		Form validForm("Standard Form", 100, 100);
		std::cout << validForm << std::endl;

		// Try to sign the form with a bureaucrat
		validForm.beSigned(middleBureaucrat);
		std::cout << validForm << std::endl;

		// Attempt to sign a form that requires a higher grade
		Form highForm("High Form", 50, 50);
		highForm.beSigned(middleBureaucrat);  // This should throw an exception
	} catch (const std::exception& e) {
		std::cerr << "Exception caught during form signing: " << e.what() << std::endl;
	}

	return 0;
}

