/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:46:30 by blaurent          #+#    #+#             */
/*   Updated: 2023/06/06 15:46:30 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void)
{
	Intern randomIntern;

	AForm* form1 = randomIntern.makeForm("presidential pardon", "dog");
	AForm* form2 = randomIntern.makeForm("robotomy request", "cat");
	AForm* form3 = randomIntern.makeForm("shrubbery creation", "fish");
	AForm* form4 = randomIntern.makeForm("test", "no");

	if (form1)
		std::cout << form1->getName() << " exist." << std::endl;
	if (form2)
		std::cout << form2->getName() << " exist." << std::endl;
	if (form3)
		std::cout << form3->getName() << " exist." << std::endl;
	if (form4)
		std::cout << form4->getName() << " exist." << std::endl;

	delete form1;
	delete form2;
	delete form3;
}