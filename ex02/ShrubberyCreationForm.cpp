/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:27:34 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/10 12:02:26 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

const std::string ShrubberyCreationForm::tree =
"              _{\\ _{\\{\\/}/}/}__               \n"
"             {/{/\\}{/{/\\}(\\}{/\\} _            \n"
"            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _        \n"
"         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}       \n"
"        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}        \n"
"       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}        \n"
"      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}       \n"
"      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}       \n"
"     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}      \n"
"      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}     \n"
"       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)      \n"
"      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}      \n"
"       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}      \n"
"         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}      \n"
"          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)       \n"
"            {/{/{\\{\\/}{/{\\{\\{\\(_)/}           \n"
"             {/{\\{\\{\\/}/}{\\{\\}/}             \n"
"              {){/ {\\/}{\\/} \\}\\}              \n"
"              (_)  \\.-'.-/                    \n"
"          __...--- |'-.-'| --...__            \n"
"   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__ \n"
" -\"    ' .  . '    |.'-._| '  . .  '   jro   \n"
" .  '-  '    .--'  | '-.'|    .  '  . '       \n"
"          ' ..     |'-_.-|                    \n"
"  .  '  .       _.-|-._ -|-._  .  '  .        \n"
"              .'   |'- .-|   '.               \n"
"  ..-'   ' .  '.   `-._.-�   .'  '  - .       \n"
"   .-' '        '-._______.-'     '  .        \n"
"        .      ~,                             \n"
"    .       .   |\\   .    ' '-.               \n"
"    ___________/  \\____________               \n"
"   /  Why is it, when you want \\              \n"
"  |  something, it is so damn   |             \n"
"  |    much work to get it?     |             \n"
"   \\___________________________/              \n";


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const {
	checkExecutionRequirements(bureaucrat);

	std::ofstream outputFile((target + "_shrubbery").c_str());
	if (!outputFile)
		throw std::runtime_error("Couldn;t open file for writing");
	outputFile << tree;
	outputFile.close();
}