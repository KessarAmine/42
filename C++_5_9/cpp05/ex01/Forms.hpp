/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Forms.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:56:11 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/23 22:37:26 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMS_HPP
# define FORMS_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Forms
{
	public:
		Forms(std::string name, int grade_tosign, int grade_toexecute);
		Forms(Forms const &obj);
		Forms();
		~Forms();
		Forms &operator=(Forms const &obj);
		std::string	get_name() const;
		std::string	get_is_signed() const;
		int			get_tosign_grade() const;
		int			get_toexecute_grade() const;
		void		sign(Bureaucrat const &bCrat);

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