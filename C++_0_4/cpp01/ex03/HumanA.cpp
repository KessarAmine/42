/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:21:26 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/08 21:18:19 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string	input, Weapon& weapon) : slot_1(weapon)
{
	set_name(input);
}

HumanA::HumanA(Weapon& weapon): slot_1(weapon)
{
	printf("HumanA constructor called\n");
}

HumanA::~HumanA()
{
	
	printf("HumanA destructor called\n");
}

void	HumanA::set_name(std::string input)
{
	name = input;
}

std::string	HumanA::get_name(void)
{
	return (name);
}

void	HumanA::set_slot_1(Weapon input)
{
	slot_1 = input;
}

std::string	HumanA::get_slot_1(void)
{
	return (slot_1.get_type());
}

void	HumanA::attack(void)
{
	std::cout << get_name() << " attacks with " << get_slot_1() << std::endl;
}
