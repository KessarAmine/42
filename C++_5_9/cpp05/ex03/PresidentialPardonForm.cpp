/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:13:06 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/26 16:29:49 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():Form("PresidentialPardonForm", 25, 5), target("(Default)")
{
	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target):Form("PresidentialPardonForm", 25, 5), target(_target)
{
	std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src):Form("PresidentialPardonForm", 25, 5), target(src.getTarget())
{
	std::cout << "PresidentialPardonForm Copy Constructor called to copy \n";
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Deconstructor \n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &obj) 
{
	if (this == &obj)
		return *this;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.get_grade() > this->get_toexecute_grade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->get_is_signed() == "False")
		throw (Form::NotSignedException());
	else
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string	PresidentialPardonForm::getTarget(void)const
{
	return (this->target);
}

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm *obj)
{
	out << "\t" << obj->get_name() << " Form:" << std::endl;
	out << "\t|-Status:" << obj->get_is_signed() << std::endl;
	out << "\t|-sign_grade :" << obj->get_tosign_grade() << std::endl;
	out << "\t|-execute_grade :" << obj->get_toexecute_grade() << std::endl;
	return (out);
}