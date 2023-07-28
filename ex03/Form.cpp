/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:58:41 by blaurent          #+#    #+#             */
/*   Updated: 2023/06/22 17:58:41 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string& _name, int _gradeToSign, int _gradeToExecute) : name(_name), isSigned(false), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
	if ( gradeToSign < 1 )
		throw AForm::GradeTooHighException();
	if ( gradeToSign > 150 )
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src) : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
}

AForm::~AForm()
{
}

AForm&	AForm::operator=(const AForm& src)
{
	if (this != &src)
		this->isSigned = src.isItSigned();
	return (*this);
}

std::string	AForm::getName() const
{
	return (this->name);
}

int	AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

bool	AForm::isItSigned() const
{
	return (this->isSigned);
}

void	AForm::beSigned(const Bureaucrat& signer)
{
	if (this->isSigned == true)
		std::cout << this->name << " is already signed." << std::endl;
	else
	{
		if (signer.getGrade() <= this->gradeToSign)
			this->isSigned = true;
		else
			throw AForm::GradeTooLowException();
	}
}

void	AForm::execute( const Bureaucrat& executor ) const
{
	if (this->isItSigned() == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
		this->doAction();
}

std::ostream&	operator<<(std::ostream& output, const AForm& src)
{
	output << "Form name: " << src.getName() << std::endl;
	output << "Grade to sign: " << src.getGradeToSign() << std::endl;
	output << "Grade to execute: " << src.getGradeToExecute() << std::endl;
	if (src.isItSigned() == true)
		output << "This form is signed" << std::endl;
	else
		output << "This form is not signed" << std::endl;
	return (output);
}