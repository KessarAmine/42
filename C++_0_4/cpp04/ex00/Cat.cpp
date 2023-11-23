/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:47:37 by kmohamed          #+#    #+#             */
/*   Updated: 2023/09/23 23:07:06 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Class Constractor called\n";
	set_type();
}

Cat::~Cat()
{
	std::cout << "Cat Class Destractor called\n";
}

void	Cat::set_type()
{
	type = "Cat";
}

void	Cat::makeSound(void) const
{
	std::cout << "khkhkh Meow" << std::endl;
}
