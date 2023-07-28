/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:25:32 by blaurent          #+#    #+#             */
/*   Updated: 2023/06/22 19:25:32 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& _target) : AForm("Presidential Pardon Form", 25, 5), target(_target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) : AForm(src)
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
    if (this != &src)
	{
		this->AForm::operator=(src);
		this->target = src.target;
	}
    return (*this);
}

std::string PresidentialPardonForm::getTarget()
{
	return (this->target);
}

void	PresidentialPardonForm::doAction() const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}