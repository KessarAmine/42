/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:15:52 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/26 16:35:52 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main(void) 
{
	// Form *SCF = new ShrubberyCreationForm("home");
	try 
	{
		Form *SCF = new ShrubberyCreationForm("home");
		Bureaucrat b1("Bob", 136);
		Bureaucrat b2("Jhon", 145);
		SCF->beSigned(b1);
		printf("ended \n");
		b1.executeForm(*SCF);
		b2.executeForm(*SCF);
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try 
	{
		Form *SCF = new RobotomyRequestForm("home");
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
		Form *SCF = new PresidentialPardonForm("home");
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
