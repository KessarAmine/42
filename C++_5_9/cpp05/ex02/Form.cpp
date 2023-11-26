/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:56:14 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/26 14:19:23 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): name("Default"), is_signed(false), grade_execute(150), grade_sign(150)
{
	std::cout << "Form: (Default) constructor, base level created" << std::endl;
}

Form::Form(const std::string _name, int _grade_sign, int _grade_execute): name(_name), is_signed(false), grade_execute(_grade_execute), grade_sign(_grade_sign)
{
	if (_grade_sign < 1 || _grade_execute < 1)
		throw GradeTooHighException();
	else if (_grade_sign > 150 || _grade_execute > 150)
		throw GradeTooLowException();
	else
		std::cout << "Form created : " << this->name << std::endl;
}

Form::Form(Form const &src): name(src.get_name()+"_copy"), is_signed(false), grade_execute(src.get_toexecute_grade()), grade_sign(src.get_tosign_grade())
{
		std::cout << "Form_Copy Constructor called to copy " << src.get_name() <<
	" into " << this->get_name() << std::endl;
	*this = src;
}

Form::~Form(void) 
{
	std::cout << this->name << " Form: Destructor called" << std::endl;
}

Form &Form::operator=(Form const &copy)
{
	std::cout << "Form Assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	//nothing to assign in this class
	return *this;
}

std::ostream &operator<<(std::ostream &out, Form const &obj)
{
	out << "\t" << obj.get_name() << " Form:" << std::endl;
	out << "\t|-Status:" << obj.get_is_signed() << std::endl;
	out << "\t|-sign_grade :" << obj.get_tosign_grade() << std::endl;
	out << "\t|-execute_grade :" << obj.get_toexecute_grade() << std::endl;
	return (out);
}

std::string Form::get_name(void) const
{
	return (this->name);
}

int Form::get_tosign_grade(void) const
{
	return (this->grade_sign);
}

int Form::get_toexecute_grade(void) const
{
	return (this->grade_execute);
}

std::string Form::get_is_signed(void) const
{
	if (this->is_signed)
		return ("True");
	else
		return ("False");
}

void Form::beSigned(Bureaucrat const &bcrat)
{
	if (this->is_signed == true)
		std::cout << "===Form signed===" << std::endl;
	else if (this->grade_sign < bcrat.get_grade()){
		std::cout << "Bureucrat: '" << bcrat.get_name() << "' cannot sign this form." << std::endl;
		throw GradeTooLowException();
	}
	else
	{
		this->is_signed = true;
		std::cout << "Bureucrat: " << bcrat.get_name() << " has signed " << this->name << std::endl;
	}
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return("Bureucrat Grade is too low and cant sign this form");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return("Grade is too high should be between 1 & 150");
}

const char *Form::NotSignedException::what(void) const throw()
{
	return ("Form needs to be signed before executing");
};
