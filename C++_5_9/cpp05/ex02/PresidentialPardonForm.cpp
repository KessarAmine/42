/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:13:06 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/24 18:15:31 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():Forms("PresidentialPardonForm", 25, 5) 
{
	this->target = "none";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):Forms("PresidentialPardonForm", 25, 5) 
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src):Forms("PresidentialPardonForm", 25, 5) 
{
	this->target = src.target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &obj) 
{
	this->target = obj.target;
	return *this;
}

void PresidentialPardonForm::action() const 
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
