/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Forms.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:56:11 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/25 19:49:47 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMS_HPP
# define FORMS_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Forms
{
	public:
		Forms(std::string name, int grade_tosign, int grade_toexecute);
		Forms(Forms const &obj);
		Forms();
		~Forms();
		Forms &operator=(Forms const &obj);
		std::string	get_name() const;
		bool		get_is_signed() const;
		int			get_tosign_grade() const;
		int			get_toexecute_grade() const;
		void		sign(Bureaucrat const &bCrat);
		void		execute(Bureaucrat const &executor) const;
		virtual void action() const = 0;
		void		be_signed(Bureaucrat &Bureaucrat);

	private:
		std::string	name;
		bool		is_signed;
		int			grade_sign;
		int			grade_execute;

	class GradeTooHighException : public std::exception {
		public:
			const char	*what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char	*what() const throw();
	};
};
	std::ostream &operator<<(std::ostream &out, Forms const &obj);
#endif