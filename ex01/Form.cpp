/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:58:41 by blaurent          #+#    #+#             */
/*   Updated: 2023/06/22 17:58:41 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& _name, int _gradeToSign, int _gradeToExecute) : name(_name), isSigned(false), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
	if (gradeToSign < 1 || gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& src) : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
}

Form::~Form()
{
}

Form& Form::operator=(const Form& src)
{
	if (this != &src)
		this->isSigned = src.isItSigned();
	return (*this);
}

std::string Form::getName() const
{
	return (this->name);
}

int Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

bool Form::isItSigned() const
{
	return (this->isSigned);
}

void Form::beSigned(const Bureaucrat& signer)
{
	if (this->isSigned == true)
		std::cout << this->name << " is already signed." << std::endl;
	else
	{
		if (signer.getGrade() <= this->gradeToSign)
			this->isSigned = true;
		else
			throw Form::GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& output, const Form& src)
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