/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:25:13 by blaurent          #+#    #+#             */
/*   Updated: 2023/06/22 19:25:13 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& _target) : AForm("Robotomy Request Form", 72, 45), target(_target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	if (this != &src)
	{
		this->AForm::operator=(src);
		this->target = src.target;
	}
	return (*this);
}

std::string	RobotomyRequestForm::getTarget()
{
	return (this->target);
}

void	RobotomyRequestForm::doAction() const
{

	if (rand() % 2 == 0)
		std::cout << "* drill noises * " << this->target << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
}