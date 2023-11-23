/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:21:26 by kmohamed          #+#    #+#             */
/*   Updated: 2023/08/24 12:10:41 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie::Zombie(std::string	input)
{
	set_name(input);
}

Zombie::Zombie()
{
	printf("Zombie constructor called\n");
}

Zombie::~Zombie()
{
	std::cout << "Zombie :" << get_name() << " destructor called\n";
}

void	Zombie::announce()
{
	printf("%s : BraiiiiiiinnnzzzZ...\n", name.c_str());
}

void	Zombie::set_name(std::string input)
{
	name = input;
}

std::string	Zombie::get_name(void)
{
	return (name.c_str());
}