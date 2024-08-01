/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:19:54 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/01 17:41:37 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileHandler.hpp"

std::string FileHandler::readFromFile(const std::string &filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		throw std::runtime_error("Could not open file: " + filename);
	}

	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	return (buffer.str());
}

void FileHandler::writeToFile(const std::string &filename, const std::string &data) {
	std::ofstream file(filename);
	if (!file.is_open()) {
		throw std::runtime_error("Could not open file to write: " + filename);
	}
	file << data;
	file.close();
}

std::string FileHandler::replaceString(const std::string &source, const std::string &s1, const std::string &s2) {
	std::string result;
	size_t pos = 0;
	size_t lastPos = 0;
	size_t s1Length = s1.length();

	while ((pos = source.find(s1, lastPos)) != std::string::npos) {
		result.append(source, lastPos, pos - lastPos);
		result.append(s2);
		lastPos = pos + s1Length;
	}
	result.append(source.substr(lastPos));
	return (result);
}
