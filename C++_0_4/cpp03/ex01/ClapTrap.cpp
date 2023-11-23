/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:35:54 by kmohamed          #+#    #+#             */
/*   Updated: 2023/08/18 19:31:42 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Default CLAPTRAP constructor called\n";
	set_name(name);
}

ClapTrap::ClapTrap()
{
	std::cout << "Default CLAPTRAP constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "CLAPTRAP destructor called" << std::endl;
}

void	ClapTrap::set_name(std::string input)
{
	name = input;
}

void	ClapTrap::set_attack_damage(unsigned int input)
{
	attack_damage = input;
}

void	ClapTrap::set_energy(unsigned int input)
{
	energy = input;
}

void	ClapTrap::set_health(unsigned int input)
{
	health = input;
}

std::string	ClapTrap::get_name()
{
	return (name);
}

unsigned int	ClapTrap::get_attack_damage()
{
	return (attack_damage);
}

unsigned int	ClapTrap::get_health()
{
	return (health);
}

unsigned int	ClapTrap::get_energy()
{
	return (energy);
}

std::ostream	&operator<<(std::ostream &stream, ClapTrap &clapTrap)
{
	stream << "Hero: " << clapTrap.get_name() << \
	"\n\tHealth: " << clapTrap.get_health() << \
	"\n\tEnergy: " << clapTrap.get_energy() << \
	"\n\tAttack Damage: " << clapTrap.get_attack_damage() << std::endl;
	return (stream);
}

void	ClapTrap::attack(std::string const & target)
{
	std::cout << this->get_name() << " Dealt " << this->get_attack_damage() \
	<< " damage to " << target << std::endl;
	this->energy -= 1;
}

void	ClapTrap::take_damage(unsigned int amount)
{
	this->health -= amount;
	std::cout << this->get_name() << " lost " \
	<< amount << " (hp)\n";
}

void	ClapTrap::be_repaired(unsigned int amount)
{
	this->health += amount;
	this->energy -= 1;
	std::cout << this->get_name() << " healed " \
	<< amount << " (hp)\n";
}
