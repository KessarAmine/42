/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Forms.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:56:14 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/25 19:12:04 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Forms.hpp"

Forms::Forms(void){
	this->name = "Default Form";
	this->is_signed = false;
	this->grade_sign = 150;
	this->grade_execute = 150;
	std::cout << "Form: Default constructor, base level created" << std::endl;
}

Forms::Forms(const std::string name, int grade_sign, int grade_execute) {
	this->name = name;
	this->is_signed = false;
	if (grade_sign < 1 || grade_execute < 1)
		throw GradeTooHighException();
	else if (grade_sign > 150 || grade_execute > 150)
		throw GradeTooLowException();
	// else if (grade_sign > grade_execute)
	// 	throw GradeTooHighException();
	else
	{
		this->grade_sign = grade_sign;
		this->grade_execute = grade_execute;
		std::cout << "Form created : " << this->name << std::endl;
	}
}

Forms::Forms(Forms const &old) {
	*this = old;
	std::cout << "Form: copy constructor called" << std::endl;
}

Forms::~Forms(void) 
{
	std::cout << this->name << " Form: Destructor called" << std::endl;
}

Forms &Forms::operator=(Forms const &copy) 
{
	this->name = copy.name;
	this->is_signed = copy.is_signed;
	this->grade_sign = copy.grade_sign;
	this->grade_execute = copy.grade_execute;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Forms const &obj)
{
	out << "\t" << obj.get_name() << " Form:" << std::endl;
	out << "Status:" << obj.get_is_signed() << std::endl;
	out << "sign_grade :" << obj.get_tosign_grade() << std::endl;
	out << "execute_grade :" << obj.get_toexecute_grade() << std::endl;
	return (out);
}

std::string Forms::get_name(void) const
{
	return (this->name);
}

int Forms::get_tosign_grade(void) const
{
	return (this->grade_sign);
}

int Forms::get_toexecute_grade(void) const
{
	return (this->grade_execute);
}

bool Forms::get_is_signed(void) const
{
	return (is_signed);
}

void Forms::sign(Bureaucrat const &bcrat) 
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

const char *Forms::GradeTooLowException::what(void) const throw()
{
	return("Bureucrat Grade is too low and cant sign this form");
}

const char *Forms::GradeTooHighException::what(void) const throw()
{
	return("Grade is too high (1->150)");
}

void Forms::be_signed(Bureaucrat &bureaucrat)
{
	if (bureaucrat.get_grade() > this->get_tosign_grade())
		throw Forms::GradeTooLowException();
	this->is_signed = true;
	std::cout << bureaucrat.get_name() << " signed " << this->get_name() << std::endl;
}

void Forms::execute(Bureaucrat const &executor) const
{
	if (executor.get_grade() > this->get_toexecute_grade())
		throw Forms::GradeTooLowException();
	if (!(this->get_is_signed())) {
		std::cout << "couldn't execute form because it's not signed" << std::endl;
		return ;
	}
	// this->action();
	std::cout << executor.get_name() << " executed " << this->get_name() << std::endl;
}
