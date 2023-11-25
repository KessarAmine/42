/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:12:55 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/25 19:10:24 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if (grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	if (grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
	this->Name = name;
	this->Grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destrcutor called\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj) 
{
	*this = obj;
}

int			Bureaucrat::get_grade() const
{
	return (this->Grade);
}

std::string	Bureaucrat::get_name() const
{
	return (this->Name);
}

const char * Bureaucrat::GradeTooHighException::what() const throw() 
{
	return "Exception : Grade too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() 
{
	return "Exception : Grade too Low";
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const & obj) 
{
	this->Grade = obj.Grade;
	return (*this);
}

std::ostream & operator<<(std::ostream &outsteam, Bureaucrat const &obj) 
{
	outsteam << "Bureaucrat '" << obj.get_name() << "' : " << obj.get_grade() << "(grade).";
	return (outsteam);
}

void Bureaucrat::dec_grade() 
{
	if (this->Grade == LOWEST)
		throw  Bureaucrat::GradeTooLowException();
	this->Grade++;
}

void Bureaucrat::inc_grade() 
{
	if (this->Grade == HIGHEST)
		throw  Bureaucrat::GradeTooHighException();
	this->Grade--;
}

void Bureaucrat::sign(Forms &form) 
{
	try
	{
		form.be_signed(*this);
	}
	catch (std::exception & e) 
	{
		std::cout << this->get_name() << " couldn’t sign "
				  << form.get_name() << " because " << e.what() << std::endl; 
	}
}

void Bureaucrat::execute(Forms const &form) 
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception & e) 
	{
		std::cout << this->get_name() << " couldn't execute "
				  << form.get_name() << " because " << e.what() << std::endl;
	}
}
