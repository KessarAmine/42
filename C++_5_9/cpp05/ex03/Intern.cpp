/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:42:47 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/26 17:12:55 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	;
}

Intern::~Intern() {
	// delete this->Form[0];
	// delete this->Form[1];
	// delete this->Form[2];
	;
}

// Remove copy constructor and assignment operator if not needed

const char* Intern::FormNotFound::what() const throw() {
	return "Form Not Found";
}

// Remove static keyword from these functions
Form* makePresident(const std::string target)
{
	return new PresidentialPardonForm(target);
}

Form* makeRobot(const std::string target)
{
	return new RobotomyRequestForm(target);
}

Form* makeShrubbery(const std::string target)
{
	return new ShrubberyCreationForm(target);
}

Form* Intern::makeForm(std::string form_name, std::string target_form)
{
	std::string froms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	Form* (*all_forms[])(const std::string) = {&makePresident, &makeRobot, &makeShrubbery};

	for (int i = 0; i < 3 && form_name != froms[i]; i++)
		return all_forms[i](target_form);
	throw Intern::FormNotFound();
}
