/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:42:21 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/26 17:13:34 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &src);
		~Intern();
		Intern &operator=(Intern const & obj);
		Form *makeForm(std::string form_name, std::string target);
		class FormNotFound : public std::exception 
		{
			public:
				const char *what() const throw();
		};
	private:
		// Form* (*all_forms[])(const std::string);
};

Form* makePresident(const std::string target);
Form* makeRobot(const std::string target);
Form* makeShrubbery(const std::string target);