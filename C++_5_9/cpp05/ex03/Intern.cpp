/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:42:47 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/25 19:50:26 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() 
{
	this->forms[0] = new ShrubberyCreationForm();
	this->forms[1] = new RobotomyRequestForm();
	this->forms[2] = new PresidentialPardonForm();
};

Intern::Intern(Intern const &src) 
{
	(void) src;

	this->forms[0] = new ShrubberyCreationForm();
	this->forms[1] = new RobotomyRequestForm();
	this->forms[2] = new PresidentialPardonForm();
};

Intern::~Intern() 
{
	// delete forms[0];
	// delete forms[1];
	// delete forms[2];
};

Intern &Intern::operator=(Intern const &obj) 
{
	(void) obj;
	return *this;
}

const char * Intern::FormNotFound::what() const throw() 
{
	return "Form Not Found";
}

Forms *Intern::makeForm(std::string form_name, std::string target) 
{
	std::string froms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 0;
	for (; i < 3; i++)
	{
		if (form_name == froms[i])
			return forms[i]->copy(target);
	}
	throw Intern::FormNotFound();
}
