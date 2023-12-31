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

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeToSign;
	const int			gradeToExecute;
	AForm();
public:
    AForm(const std::string& _name, int _gradeToSign, int _gradeToExecute);
	AForm(const AForm& src);
	virtual ~AForm();

	AForm&		operator=(const AForm& src);

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

std::ostream& operator<<(std::ostream& output, const AForm& src);

#endif