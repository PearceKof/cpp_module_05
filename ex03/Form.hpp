/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:58:37 by blaurent          #+#    #+#             */
/*   Updated: 2023/06/22 17:58:37 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeToSign;
	const int			gradeToExecute;
	Form();
public:
    Form(const std::string& _name, int _gradeToSign, int _gradeToExecute);
	Form(const Form& src);
	~Form();

	Form&		operator=(const Form& src);

	std::string	getName() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;
	bool		isItSigned() const;

	void		beSigned(const Bureaucrat& signer);

	void        execute(const Bureaucrat& executor) const;
	virtual void doAction() const = 0;

	class NotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw() { return "Form not signed"; }
	};
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

std::ostream& operator<<(std::ostream& output, const Form& src);

#endif