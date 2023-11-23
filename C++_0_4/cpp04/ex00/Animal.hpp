/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:00:49 by kmohamed          #+#    #+#             */
/*   Updated: 2023/09/23 23:11:52 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H
#include <iostream>
#include <string>

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		virtual void	set_type();
		virtual void	makeSound() const;
		std::string		get_type() const;

	protected:
		std::string	type;
};
#endif