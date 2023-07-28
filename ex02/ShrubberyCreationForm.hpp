/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:24:26 by blaurent          #+#    #+#             */
/*   Updated: 2023/06/22 19:24:26 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string   target;
	void doAction() const;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(const std::string& _target);
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
	~ShrubberyCreationForm();

	std::string	getTarget();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);

};

#endif