/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:56:11 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/26 17:15:59 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(std::string name, int grade_tosign, int grade_toexecute);
		Form(Form const &obj);
		Form();
		~Form();
		Form &operator=(Form const &obj);
		std::string	get_name() const;
		std::string	get_is_signed() const;
		int			get_tosign_grade() const;
		int			get_toexecute_grade() const;
		void		beSigned(Bureaucrat const &bCrat);

	private:
		std::string	const	name;
		bool				is_signed;
		int			const	grade_sign;
		int			const	grade_execute;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
	std::ostream &operator<<(std::ostream &out, Form const &obj);
#endif