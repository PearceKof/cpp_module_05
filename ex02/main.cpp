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

#include <cstdlib> // srand
#include <ctime> // time
#include <iostream> // cerr


int	main()
{
	srand(time(0));

	try
	{
		Bureaucrat				bob("Robert", 24);

		PresidentialPardonForm	pp("Larry");
		std::cout << pp << std::endl;
		RobotomyRequestForm		rr("Henry");
		std::cout << rr << std::endl;
		ShrubberyCreationForm	sc("Living_room");
		std::cout << sc << std::endl;

		bob.signForm(pp);
		bob.executeForm(pp);

		bob.signForm(rr);
		bob.executeForm(rr);

		bob.signForm(sc);
		bob.executeForm(sc);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	return 0;
}