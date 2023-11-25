/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:12:52 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/25 18:37:23 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

#include <iostream>
#include <string>
#include "Forms.hpp"

#define LOWEST 150
#define HIGHEST 1

class Forms;
class Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &obj);
		~Bureaucrat();
		std::string	get_name() const;
		int			get_grade() const;
		void		inc_grade();
		void		dec_grade();
		void		sign(Forms &form);
		void		execute(Forms const &form);
		Bureaucrat &operator=(Bureaucrat const &obj);
		class GradeTooHighException : public std::exception {
			public:
				const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char	*what() const throw();
		};
	private:
		std::string	Name;
		int			Grade;
};
std::ostream &operator<<(std::ostream &outsteam, Bureaucrat const &obj);
#endif