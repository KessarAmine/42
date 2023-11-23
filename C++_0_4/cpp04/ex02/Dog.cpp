/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:47:34 by kmohamed          #+#    #+#             */
/*   Updated: 2023/09/23 23:50:45 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Class Constractor called\n";
	set_type();
	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog Class Destractor called\n";
	delete this->brain;
}

void	Dog::set_type()
{
	type = "Dog";
}

void	Dog::makeSound(void) const
{
	std::cout << "kuramaaaa" << std::endl;
}

Brain	*Dog::get_brain(void) const
{
	return (this->brain);
}
