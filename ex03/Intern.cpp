/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:24:57 by blaurent          #+#    #+#             */
/*   Updated: 2023/07/25 17:59:39 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& src)
{
    *this = src;
}

Intern::~Intern()
{
}

Intern&	Intern::operator=(const Intern& src)
{
    (void)src;
    return (*this);
}

Form	*Intern::makeForm(std::string formName, std::string target)
{
	int i(0);
	std::string form[] = {"robotomy request", "srubbery creation", "presidential pardon"};

	for(i = 0 ; i < 3 ; i++)
	{
		if (formName.compare(form[i]))
			break;
	}
	if (i < 3)
	{
		std::cout << "Intern creates " << formName << std::endl;
		switch (i)
		{
		case 0:
			return (new RobotomyRequestForm(target));
			break;
		case 1:
			return (new ShrubberyCreationForm(target));
			break;
		case 2:
			return (new PresidentialPardonForm(target));
			break;
		default:
			break;
		}
	}
	std::cout << "Intern cannot create " << name << " form" << std::endl;
	return (NULL);
}