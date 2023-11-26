/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:13:56 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/26 16:41:41 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():Form("RobotomyRequestForm", 72, 45), target("(Default)")
{
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target):Form("RobotomyRequestForm", 72, 45), target(_target)
{
	std::cout << "RobotomyRequestForm Constructor for target\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src):Form("RobotomyRequestForm", 72, 45), target(src.getTarget())
{
	std::cout << "RobotomyRequestForm Copy Constructor called to copy \n";
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Deconstructor\n";
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.get_grade() > this->get_toexecute_grade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->get_is_signed() == "False")
		throw (Form::NotSignedException());
	if (rand() &1)
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	else 
		std::cout << this->target << " robotomy failed." << std::endl;
}

// ostream Overload
std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm *obj)
{
	out << "\t" << obj->get_name() << " Form:" << std::endl;
	out << "\t|-Status:" << obj->get_is_signed() << std::endl;
	out << "\t|-sign_grade :" << obj->get_tosign_grade() << std::endl;
	out << "\t|-execute_grade :" << obj->get_toexecute_grade() << std::endl;
	return (out);
}

std::string	RobotomyRequestForm::getTarget(void)const
{
	return (this->target);
}
