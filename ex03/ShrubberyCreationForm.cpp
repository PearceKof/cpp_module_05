/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:24:29 by blaurent          #+#    #+#             */
/*   Updated: 2023/06/22 19:24:29 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _target) : AForm("Shrubbery Creation Form", 145, 137), target(_target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src) : AForm(src)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm&   	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != &src)
	{
		this->AForm::operator=(src);
		this->target = src.target;
	}
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget()
{
	return (this->target);
}

void	ShrubberyCreationForm::doAction() const
{
	std::string	filename(this->getName() + "_shrubbery");
	std::ofstream	file(filename.c_str());

	file << "               .0000000." << std::endl;
	file << "       ,,,.   ,000000000,  .oo8888o." << std::endl;
	file << "    ,&%%&%&&%,00000/000000,8888&88&8o" << std::endl;
	file << "   ,%&&%&&%&&%,000&000/00088&88888&88'" << std::endl;
	file << "   %&&%&%&/%&&%00&00/ /00088888&88888'" << std::endl;
	file << "   %&&%& %&%%&&00& V /00' `88&8 `/88'" << std::endl;
	file << "   `&%& ` /%&'    |.|       |  '|8'" << std::endl;
	file << "       |o|        | |       |*-*|" << std::endl;
	file << "       |.|        | |      /|   |" << std::endl;
	file << "       | |        | |       |   |" << std::endl;
	file.close();
}