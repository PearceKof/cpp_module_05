/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:25:38 by blaurent          #+#    #+#             */
/*   Updated: 2023/06/22 19:25:38 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
	void	doAction() const;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(const std::string& _target);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(const PresidentialPardonForm& src);

	std::string getTarget();
};

#endif