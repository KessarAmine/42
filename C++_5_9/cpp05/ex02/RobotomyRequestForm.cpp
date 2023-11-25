/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:13:56 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/24 18:17:06 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():Forms("RobotomyRequestForm", 72, 45) 
{
	this->target = "none";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):Forms("RobotomyRequestForm", 72, 45) 
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src):Forms("RobotomyRequestForm", 72, 45) 
{
	this->target = src.target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &obj) 
{
	this->target = obj.target;
	return *this;
}

void RobotomyRequestForm::action() const 
{
	srand((long) this);
	if (rand() & 1) 
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	else 
		std::cout << this->target << " robotomy failed." << std::endl;
}
