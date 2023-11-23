/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:07:55 by kmohamed          #+#    #+#             */
/*   Updated: 2023/08/18 19:31:54 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default SCAVTRAP constructor called\n";
	ClapTrap();
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "SCAVTRAP constructor called\n";
	set_health(100);
	set_energy(50);
	set_attack_damage(20);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << get_name() << " has entered in Gate keeper mode.\n";
}
