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

Bureaucrat::Bureaucrat() : name("Employee"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade)
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : name(src.name), grade(src.grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
		this->grade = src.getGrade();
	return *this;
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
