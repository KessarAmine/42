/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:12:50 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/26 14:11:35 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) 
{
	std::cout << "1st test" << std::endl;
	try
	{
		Bureaucrat bureaucrat("bob", 2);
		std::cout << bureaucrat << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) 
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) 
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "2nd test" << std::endl;
	try 
	{
		Bureaucrat bureaucrat1("bob", 1);
		bureaucrat1.inc_grade();
		std::cout << bureaucrat1 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) 
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) 
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "3rd test" << std::endl;
	try 
	{
		Bureaucrat bureaucrat2("bob", 151);
		bureaucrat2.dec_grade();
		std::cout << bureaucrat2 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) 
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) 
	{
		std::cerr << e.what() << std::endl;
	}
}
