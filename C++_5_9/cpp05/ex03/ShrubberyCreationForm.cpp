/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:11:48 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/26 16:36:22 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():Form("ShrubberyCreationForm", 145, 137), target("(Default)")
{
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target):Form("ShrubberyCreationForm", 145, 137), target(_target)
{
	std::cout << "ShrubberyCreationForm Constructor for target " << this->getTarget() << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src):Form("ShrubberyCreationForm", 145, 137), target(src.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy Constructor called to copy " << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Deconstructor " << this->get_name() << " called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.get_grade() > this->get_toexecute_grade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->get_is_signed() == "False")
		throw (Form::NotSignedException());
	std::ofstream outFile(this->target + "_shrubbery");
	if (!outFile) 
	{
		std::cerr << "can't open/create" << this->target + "_shrubbery" << std::endl;
		return ;
	}
	outFile << "      *   \n";
	outFile << "     / \\   \n";
	outFile << "    / _ \\  \n";
	outFile << "   /_/ \\_\\ \n";
	outFile << "     _|_   \n";
	std::cout << "File created successfully: " << target << "_shrubbery\n";
}

// Getter
std::string	ShrubberyCreationForm::getTarget(void)const
{
	return (this->target);
}

// ostream Overload
std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm *obj)
{
	out << "\t" << obj->get_name() << " Form:" << std::endl;
	out << "\t|-Status:" << obj->get_is_signed() << std::endl;
	out << "\t|-sign_grade :" << obj->get_tosign_grade() << std::endl;
	out << "\t|-execute_grade :" << obj->get_toexecute_grade() << std::endl;
	return (out);
}
