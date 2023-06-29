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
#include "Form.hpp"

int main( void )
{

    try
    {
        Bureaucrat bureaucrat("Bob",11);
        Form form("formName", 10);

        std::cout << form << std::endl;

        bureaucrat.signForm(form);
        bureaucrat.incrementGrade();
        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	std::cout << "----test 1: grade too low-----" << std::endl;
    try
	{
        Form form("formName", 1000);
    }
	catch (Form::GradeTooLowException& e)
	{
        std::cout << e.what() << std::endl;
    }

	std::cout << "\n----test 2: grade too high---" << std::endl;
	try
	{
        Form form("formName", 0);
    }
	catch (Form::GradeTooHighException& e)
	{
        std::cout << e.what() << std::endl;
    }

	std::cout << "\nEnd of program.\n" << std::endl;

    return (0);
}
