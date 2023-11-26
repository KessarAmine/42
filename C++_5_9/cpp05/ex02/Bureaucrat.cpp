/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:12:55 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/26 16:01:18 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade):Name(name) 
{
	if (grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	if (grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
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

void		Bureaucrat::set_grade(int grade)
{
	this->Grade = grade;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() 
{
	return "Exception : Grade too high";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() 
{
	return "Exception : Grade too Low";
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const & obj) 
{
	this->Grade = obj.Grade;
	return (*this);
}

std::ostream	&operator<<(std::ostream &outsteam, Bureaucrat const &obj) 
{
	outsteam << "Bureaucrat '" << obj.get_name() << "' : " << obj.get_grade() << "(grade).";
	return (outsteam);
}

void	Bureaucrat::dec_grade()
{
	if (this->Grade == LOWEST)
		throw  Bureaucrat::GradeTooLowException();
	this->Grade++;
}

void	Bureaucrat::inc_grade()
{
	if (this->Grade == HIGHEST)
		throw  Bureaucrat::GradeTooHighException();
	this->Grade--;
}

void	Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
}

void	Bureaucrat::executeForm(Form &form)const
{
	if ((int)this->get_grade() > form.get_toexecute_grade())
		throw (Bureaucrat::GradeTooLowException());
	else
		form.execute(*this);
}
