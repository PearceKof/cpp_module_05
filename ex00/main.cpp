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

int main()
{
	std::cout << "----test 1: grade too high----" << std::endl;
    try
	{
        Bureaucrat bob("Bob", 1);

        std::cout << bob << std::endl;

        bob.incrementGrade();
    }
	catch (Bureaucrat::GradeTooHighException& e)
	{
        std::cout << "Exception catched: " << e.what() << std::endl;
    }

	std::cout << "\n----test 2: grade too low-----" << std::endl;
	try
	{
        Bureaucrat bib("Bib", 150);

        std::cout << bib << std::endl;

        bib.decrementGrade();
    }
	catch (Bureaucrat::GradeTooLowException& e)
	{
        std::cout << "Exception catched: " << e.what() << std::endl;
    }

	std::cout << "\n----test 3: grade is fine-----" << std::endl;
	try
	{
        Bureaucrat bab("bab", 100);

        std::cout << bab << std::endl;

        bab.decrementGrade();
		std::cout << "src: " << bab << std::endl;
		
		Bureaucrat cpy(bab);
		std::cout << "cpy: " << cpy << std::endl;
    }
	catch (std::exception& e)
	{
        std::cout << "Exception catched: " << e.what() << std::endl;
    }

	std::cout << "\nEnd of program.\n" << std::endl;

    return (0);
}