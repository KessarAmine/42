/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:21:26 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/08 21:27:47 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string	input)
{
	set_name(input);
}

HumanB::~HumanB()
{
	
	printf("HumanB destructor called\n");
}

void	HumanB::set_name(std::string input)
{
	name = input;
}

std::string	HumanB::get_name(void)
{
	return (name);
}

void	HumanB::set_slot_1(Weapon& weapon)
{
	slot_1 = &weapon;
}

std::string	HumanB::get_slot_1(void)
{
	return (slot_1->get_type());
}

void	HumanB::attack(void)
{
	std::cout << get_name().c_str() << " attacks with " << get_slot_1() << std::endl;
}
