/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:46:51 by blaurent          #+#    #+#             */
/*   Updated: 2023/06/06 15:46:51 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade)
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
	// std::cout << this->name << " created with the grade " << this->grade << "." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : name(src.name), grade(src.grade)
{
	// std::cout << this->name << " created with the grade " << this->grade << "." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << this->name << " destroyed." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
		this->grade = src.getGrade();
	return (*this);
}



std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}



void Bureaucrat::incrementGrade()
{
	if ((this->grade - 1) < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if ((this->grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}



std::ostream& operator<<(std::ostream& output, const Bureaucrat& src)
{
	output << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return (output);
}



void	Bureaucrat::signForm(Form& formToSign)
{
	if (formToSign.isItSigned() == true)
		std::cout << formToSign.getName() << " is already signed." << std::endl;
	else
	{
		try
		{
			formToSign.beSigned(*this);
			std::cout << this->name << " signed " << formToSign.getName() << "." << std::endl;
		}
		catch(Form::GradeTooLowException &e)
		{
			std::cout << this->name << " couldn't sign " << formToSign.getName() << " because " << e.what() << std::endl;
		}
	}
}
