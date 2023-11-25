/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:11:48 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/25 19:15:14 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():Forms("ShrubberyCreationForm", 145, 137) 
{
	this->target = "none";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):Forms("ShrubberyCreationForm", 145, 137) 
{
	this->target = target;
	this->action();
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src):Forms("ShrubberyCreationForm", 145, 137) 
{
	this->target = src.target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj) 
{
	this->target = obj.target;
	return *this;
}

void ShrubberyCreationForm::action() const
{
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
