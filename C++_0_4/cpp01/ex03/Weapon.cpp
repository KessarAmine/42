/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:21:26 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/08 21:21:31 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string	input)
{
	set_type(input);
}

Weapon::Weapon()
{
	printf("Weapon constructor called\n");
}

Weapon::~Weapon()
{
	
	printf("Weapon destructor called\n");
}

void	Weapon::set_type(std::string input)
{
	this->type = input;
}

std::string	Weapon::get_type(void)
{
	return (type);
}
