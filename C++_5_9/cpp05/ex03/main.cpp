/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:39:49 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/26 17:11:33 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void) 
{
	Intern intern;

	try 
	{
		Form *SCF = intern.makeForm("ShrubberyCreationForm", "home");
		Bureaucrat b1("Bob", 136);
		Bureaucrat b2("Jhon", 145);
		b2.signForm(*SCF);
		b1.executeForm(*SCF);
		b2.executeForm(*SCF);
	}
	catch (std::exception & e) 
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try 
	{
		Form *SCF = intern.makeForm("RobotomyRequestForm", "home");
		Bureaucrat b1("Bob2", 44);
		Bureaucrat b2("Jhon2", 72);
		b2.signForm(*SCF);
		b1.executeForm(*SCF);
		b2.executeForm(*SCF);
	}
	catch (std::exception & e) 
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Form *SCF = intern.makeForm("PresidentialPardonForm", "home");
		Bureaucrat b1("Bob2", 5);
		Bureaucrat b2("Jhon2", 24);
		b2.signForm(*SCF);
		b1.executeForm(*SCF);
		b2.executeForm(*SCF);
	}
	catch (std::exception & e) 
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try 
	{
		Form *SCF = intern.makeForm("None Existing Form", "home");
		Bureaucrat b1("Bob2", 5);
		Bureaucrat b2("Jhon2", 24);
		b2.signForm(*SCF);
		b1.executeForm(*SCF);
		b2.executeForm(*SCF);
	}
	catch (std::exception & e) 
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
