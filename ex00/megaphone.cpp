/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:26:09 by rpambhar          #+#    #+#             */
/*   Updated: 2024/07/31 13:45:19 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

std::string capitalize(const char *str)
{
	std::string result = str;

	for (std::size_t i = 0; i < result.size(); ++i)
		result[i] = std::toupper(result[i]);
	return (result);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::cout << capitalize(argv[i]);
			std::cout << " ";
		}
		std::cout << "\n";
	}
}