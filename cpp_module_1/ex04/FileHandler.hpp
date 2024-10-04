/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:05:33 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/01 17:15:09 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEHANDLER_HPP
# define FILEHANDLER_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class FileHandler {
	public:
		static std::string readFromFile(const std::string &filename);
		static void writeToFile(const std::string &filename, const std::string &data);
		static std::string replaceString(const std::string &source, const std::string &s1, const std::string &s2);
};

#endif