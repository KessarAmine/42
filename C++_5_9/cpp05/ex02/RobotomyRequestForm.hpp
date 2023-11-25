/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:05:55 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/24 18:16:49 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Forms.hpp"
#include <iostream>
#include <string>

class RobotomyRequestForm : public Forms
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(RobotomyRequestForm const &obj);
		void action() const;
	
	private:
		std::string target;
};
