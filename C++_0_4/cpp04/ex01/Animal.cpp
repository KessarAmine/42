/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:47:39 by kmohamed          #+#    #+#             */
/*   Updated: 2023/09/23 23:16:45 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Class Constractor called\n";
	set_type();
}

Animal::~Animal()
{
	std::cout << "Animal Class Destractor called\n";
}

void	Animal::makeSound() const
{
	std::cout << "Animal incoming " << std::endl;
}

void	Animal::set_type()
{
	type = "Animal";
}

std::string	Animal::get_type(void) const
{
	return (type);
}

Brain	*Animal::get_brain() const
{
	return (NULL);
}
