/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:47:04 by blaurent          #+#    #+#             */
/*   Updated: 2023/06/06 15:47:04 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const	std::string name;
	int		grade;
public:
	Bureaucrat();
	Bureaucrat(std::string _name, int _grade);
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat();

	Bureaucrat	&operator=(const Bureaucrat& src);

	std::string	getName() const;
	int			getGrade() const;

	void	incrementGrade();
	void	decrementGrade();

	void	signForm(AForm& formToSign);

	void	executeForm(AForm const& form);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw() { return "Grade too high"; }
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw() { return "Grade too low"; }
	};
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& src);

#endif