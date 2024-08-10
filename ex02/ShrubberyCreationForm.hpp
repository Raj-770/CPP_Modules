/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 09:50:16 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/10 10:34:41 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string target;
		static const std::string tree;

	public:
		ShrubberryCreationForm(const std::string &target);
		ShrubberryCreationForm(const ShrubberyCreationForm& other);
		ShrubberryCreationForm& operator=(const ShrubberryCreationForm& other);
		~ShrubberryCreationForm();

		void execute(const Bureaucrat &executor) const;
}

#endif