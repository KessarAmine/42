/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:32:05 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/26 14:53:30 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void) 
{
	std::cout << "<<<<<<<<<<<<1st test>>>>>>>>>>>" << std::endl;
	try 
	{
		Form form1("Player Contract", 150, 150);
		Bureaucrat bCrat1("Richarlison", 1);
		bCrat1.signForm(form1);
		std::cout << "Welcome to the Club" << std::endl;
		bCrat1.inc_grade();
	}
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}

	std::cout  << "<<<<<<<<<<<<2nd test>>>>>>>>>>>" << std::endl;
	try 
	{
		Form form1("Drivers License", 1, 1);
		std::cout << form1;
		Bureaucrat bCrat1("Caitlyn Jenner", 150);
		form1.beSigned(bCrat1);
	}
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "<<<<<<<<<<<<3rd test>>>>>>>>>>>" << std::endl;
	Form form1;
	Form pContract("PlayerContract", 1, 1);
	Form pApplication("Passport Application", 150, 150);
	Form copyApplication(pApplication);
	std::cout << form1;
	form1 = pContract;
	std::cout << "Uknown Form should become a Player Contract now" << std::endl;
	std::cout << form1;
	std::cout << copyApplication;
	std::cout << "<<<<<<<<<<<<<end>>>>>>>>>>>>>" << std::endl;
}
